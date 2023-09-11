//10558-Uniform Generator.c
#include<stdio.h>
#include<string.h>
char sHave[100000];
int step, mod, have, next;
int main(){
	while(EOF!=scanf("%ld%ld",&step,&mod)){
		next=0;
		memset(sHave, 0, mod);
		sHave[0]=1;
		for(have=1;have<mod;++have){
			next=(next+step)%mod;
			if(sHave[next]++)break;
		}
		printf("%10ld%10ld    ",step,mod);
		if(have==mod)printf("Good Choice\n\n");
		else printf("Bad Choice\n\n");
	}
	return 0;
}