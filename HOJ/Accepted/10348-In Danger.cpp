//10348-In Danger.cpp
#include<cstdio>
int num, exp;
int main(){
	while(scanf("%lde%ld",&num,&exp)){
		if(!num&&!exp) break;
		for(int i=0;i<exp;++i)num*=10;
		exp=1;
		while(exp<=num)exp<<=1;
		exp>>=1;
		if(exp==num)puts("1");
		else printf("%ld\n", (num-exp)*2+1);
	}
}
