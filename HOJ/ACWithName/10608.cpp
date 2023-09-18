#include<cstdio>

typedef unsigned __int64 ull;
const ull INWEI = 50000000000000ULL;
const ull GETLAST = INWEI*2;
const ull MAX = GETLAST*1000;
const ull DIVI= MAX*10;

int num,ncase,i;
struct TwoNum{
	short val;
	short exp;
	void Print(){printf("2^-%ld = %d.%03dE-%d\n",num
		,val/1000,val%1000,exp);}
}res[9001];

void Initres(){
	ull tv=MAX;short te=0;bool isBig;
	res[0].exp=0;
	for(i=1;i<9010;i++){
		tv*=5ULL;
		isBig=tv<DIVI;
		te=res[i-1].exp+isBig;
		if(!isBig)tv/=10;
		res[i].val=(short)(tv/GETLAST);
		if((tv%GETLAST)>=INWEI)res[i].val+=1;
		res[i].exp=te;
	}
}

int main(){
	Initres();
	char c;
	scanf("%ld",&ncase);
	while(ncase--){
		while(scanf("%ld",&num);
		res[num].Print();
	}
	return 0;
}
