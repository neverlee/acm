//10649-Continuous Fractions Again.cpp
#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned __int64 uint;
int row, tmp;
char str[1000];
uint utmp;
uint Gcd(uint a, uint b){
	while(b){utmp=a%b;a=b;b=utmp;}
	return a;
}
int main(){
	while(scanf("%ld%ld",&row,&tmp),row){
		vector<uint> vnum;
		scanf("%s%s",str,str);
		sscanf(str,"%I64u",&utmp);
		vnum.push_back(utmp);
		for(;row>4;row-=2){
			scanf("%s%s",str,str);
			sscanf(str,"%*[.]%I64u",&utmp);
			vnum.push_back(utmp);
		}
		scanf("%s",str);
		uint son=1,mother=1;
		vector<uint>::reverse_iterator it=vnum.rbegin();
		for(;it!=vnum.rend();++it){
			utmp=son;son=mother;mother=utmp;
			son+=mother*(*it);
			utmp=Gcd(son,mother);
			son/=utmp;
			mother/=utmp;
		}
		printf("%I64u %I64u\n", son, mother);
	}
	return 0;
}
