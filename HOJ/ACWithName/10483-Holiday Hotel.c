//10483-Holiday Hotel.c
#include<stdio.h>
int i,n,d,c,sd[10001];
int main(){
	while(scanf("%ld",&n),n){
		for(i=0;i<10001;++i)sd[i]=10001;
		for(i=0;i<n;++i){scanf("%ld%ld",&d,&c);if(sd[d]>c)sd[d]=c;}
		c=10001;
		for(n=0,i=0;i<10001;++i)if(sd[i]<c){++n;c=sd[i];}
		printf("%ld\n",n);
	}
	return 0;
}