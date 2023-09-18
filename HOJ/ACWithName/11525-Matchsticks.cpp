//11525-Matchsticks.cpp
#include<cstdio>
int need[10]={6,2,5,5,4,5,6,3,7,6};
int dps[101];
void Init(){
	int s,n,k;
	for(int i=0;i<=100;++i)dps[i]=1000000;
	for(int i=1;i<=1000000;++i){
		s=0;n=i;
		while(n>0){s+=need[n%10];n/=10;}
		dps[s]=dps[s]<i?dps[s]:i;
	}
}
void OutMax(int num){
	if(num%2==1){putchar('7');num-=3;}
	num>>=1;
	for(int i=0;i<num;++i)putchar('1');
}
void OutMin(int num){
	int ei=0;
	if(num>=30)ei=(num-24)/7;
	num-=(ei*7);
	printf("%ld",dps[num]);
	for(int i=0;i<ei;++i)putchar('8');
}
int main(){
	Init();
	int iCase, num;scanf("%ld",&iCase);
	while(iCase--){
		scanf("%ld",&num);
		OutMin(num);
		putchar(' ');
		OutMax(num);
		putchar('\n');
	}
}
