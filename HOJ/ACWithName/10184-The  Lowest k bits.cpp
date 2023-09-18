//10184-The  Lowest k bits.cpp
#include<cstdio>

int main(){
	int ncase;scanf("%ld",&ncase);
	unsigned a,b,k;
	while(ncase--){
		scanf("%lu%lu%lu",&a,&b,&k);
		a=(unsigned)(a*b);
		b=-1;b>>=32-k;
		printf("%lu\n",a&b);
	}
	return 0;
}