#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Super{
	int type;//0 three  1 long
	int id;
	Super(){}
	Super( int t, int i ) {
		set( t, i );
	}
	void set( int t, int i ) {
		type = t;
		id = i;
	}
	friend bool operator==( const Super &sa, const Super &sb ) {
		return sa.type==sb.type && sa.id==sb.id;
	}
	friend bool operator<( const Super &sa, const Super &sb ) {
		if( sa.type<sb.type ) return 1;
		if( sa.type==sb.type && sa.id<sb.id ) return 1;
		return 0;
	}
};
class Card{
public:
	vector<int> data;
	vector<bool> fred;
	vector<bool> fans;
	int head;
	vector<Super> sk;
	void input() {
		int i;
		char str[30];
		scanf( "%s", str );
		for( i=0; i<28; i+=2 ) {
			int a = str[i]-'1';
			if( str[i+1]=='s' ) a+=9;
			if( str[i+1]=='t' ) a+=18;
			data.push_back(a);
		}
		fred.resize(data.size());
		sort( data.begin(), data.end() );
	}
	void deal_last() {
		int i;
		vector<Super> skp = sk;
		sort( sk.begin(), sk.end() );
		check();
		sk=skp;
	}
	void work() {
		int i;
		fill( fred.begin(), fred.end(), 1 );
		fans.resize(12);
		sk.resize(4);
		fill( fans.begin(), fans.end(), 0 );
		for( i=0 ; i<data.size(); ++i ) {
			if( i==data.size()-1 || data[i]!=data[i+1] ) {
				if( data[i]==data[i-1] ) {
					fred[i]=fred[i-1]=0;
					head = data[i];
					dfs( 0 );
					fred[i]=fred[i-1]=1;
				}
			}
		}
	}
	int find_card( int cd, bool fr=1 ) {
		int i;
		for( i=0; i<data.size(); ++i )
			if( fred[i]==fr && data[i]==cd ) return i;
		return -1;
	}
	bool set_three( int pos ) {
		int i, cnt;
		for( i=pos, cnt=0; i<data.size(); ++i )
			if( fred[i] && data[i]==data[pos] ) ++cnt;
		if( cnt<3 ) return false;
		for( i=pos, cnt=0; cnt<3; ++i )
			if( fred[i]==1 && data[i]==data[pos] ) {
				fred[i]=false;
				++cnt;
			}
		return true;
	}
	void back_three( int pos ) {
		int i, cnt;
		for( i=pos, cnt=0; cnt<3; ++i )
			if( fred[i]==0 && data[i]==data[pos] ) {
				fred[i]=true;
				++cnt;
			}
	}
	
	bool set_long( int pos ) {
		int i, tmp, k;
		tmp = data[pos];
		if( tmp%9>6 ) return false;
		if( !( find_card(tmp)>=0 && find_card(tmp+1)>=0 && find_card(tmp+2)>=0 ) ) 	return false;
		for( i=0; i<3; ++i ) {
			k = find_card(tmp+i);
			fred[k]=0;
		}
		return true;
	}
	void back_long( int pos ) {
		int i, tmp, k;
		tmp = data[pos];
		for( i=0; i<3; ++i ) {
			k = find_card(tmp+i,0);
			fred[k]=1;
		}
	}
	void dfs( int cp ) {
		int i;
		for( i=0; i<data.size() && fred[i]==0; ++i );
		if( i==data.size() ) return;
		if( set_three(i) ) {
			sk[cp].set( 0, data[i] );
			if( cp==3 ) deal_last();
			else dfs( cp+1 );
			back_three( i );
		}
		if( set_long(i) ) {
			sk[cp].set( 1, data[i] );
			if( cp==3 ) deal_last();
			else dfs( cp+1 );
			back_long( i );
		}
	}
	bool is_dyj() {
		int i;
		for( i=0; i<14; ++i ) {
			int c = data[i]%9;
			if( c==0 || c==8 ) return false;
		}
		return true;
	}
	bool is_sst( bool type ) {
		Super sp1=sk[0]; sp1.id+=9;
		Super sp2=sk[0]; sp2.id+=18;
		if( sk[0].type==type && find_group(sp1)>=0 && find_group(sp2)>=0 )
			return 1;
		sp1 = sp2 = sk[1];
		sp1.id+=9; sp2.id+=18;
		if( sk[1].type==type && sk[2]==sp1 && sk[3]==sp2 ) return 1;
		return 0;
	}
	bool is_qys() {
		int i;
		int c = data[0]/9;
		for( i=0; i<14; ++i )
			if( data[i]/9!=c ) return false;
		return true;
	}
	bool is_qlt() {
		int i;
		for( i=0; i<data.size(); ++i ) {
			int c = data[i]%9;
			if( c>0 && c<8 ) return false;
		}
		return true;
	}
	int find_group( Super sp, int pos=0 ) {
		int i;
		for( i=pos; i<4; ++i )
			if( sk[i]==sp ) return i;
		return -1;
	}
	void check() {
		int i;
		//*平和（一番）：4个顺子组成；
		if( sk[0].type==1 ) fans[0]=1;
		//?断幺九（一番）：胡牌的时候手上只有2-8的数字组成的牌型；
		if( is_dyj() ) fans[1]=1;
		//*一杯口（一番）：同花色同数值的顺子两组；
		for( i=0; i<3; ++i )
			if( sk[i].type==1 && sk[i].id==sk[i+1].id )
				fans[2]=1;
		//*混全带幺九（一番）：全部的顺子，刻子中都含有数字1或9；
		for( i=0; i<4; ++i )
			if( !(
				( sk[i].type==0 && (sk[i].id%9==0||sk[i].id%9==8) ) ||
				( sk[i].type==1 && (sk[i].id%9==0||sk[i].id%9==6) )
			) ) break;
		if( i==4 ) fans[3]=1;
		//三色同顺（一番）：三种花色同数值的顺子各一组；
		if( is_sst(1) ) fans[4]=1;
		//一气贯通（一番）：由同花色一至九组成顺子；
		if( ( find_group(Super(1,0))>=0 && find_group(Super(1,3))>=0
				&& find_group(Super(1,6))>=0 ) || 
				( find_group(Super(1,9))>=0 && find_group(Super(1,12))>=0
				&& find_group(Super(1,15))>=0 ) ||
				( find_group(Super(1,18))>=0 && find_group(Super(1,21))>=0
				&& find_group(Super(1,24))>=0 ) )
			fans[5]=1;
		//*一色三顺（两番）：同花色同数值顺子三组；
		if( ( sk[0].type==1 && sk[0].id==sk[2].id ) ||
			( sk[1].type==1 && sk[1].id==sk[3].id ) )
			fans[6]=1;
		//*对对和（两番）：四组刻子；
		if( sk[3].type==0 ) fans[7]=1;
		//*两杯口（三番）：由两组不同的一杯口组成；
		if( sk[0].type==1 && sk[1].id != sk[2].id
				&& sk[0].id==sk[1].id && sk[2].id==sk[3].id )
			fans[8]=1;
		//三色同刻（三番）：三种花色同数值的刻子各一组；
		if( is_sst(0) ) fans[9]=1;
		//*清一色（六番）：全部由同一种花色的顺子，刻子及雀头组成；
		if( is_qys() ) fans[10]=1;
		//*清老头（六番）：全部由1或9的刻子和雀头组成；
		if( is_qlt() ) fans[11]=1;
	}
	int get_times() {
		int total=0;
		int i;
		for( i=0; i<fans.size(); ++i )
		if( fans[i] ){
			if( i<6 ) total+=1;
			else if( i<8 ) total+=2;
			else if( i<10 ) total+=3;
			else total+=6;
		}
		return total;
	}
};

int main() {
	int n;
	scanf( "%d", &n );
	while( n-- ) {
		Card myc;
		myc.input();
		myc.work();
		printf( "%d\n", myc.get_times() );
	}
	return 0;
}