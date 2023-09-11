//10044-Connecting People.cpp
#include<cstdio>
int k, b, b1, n, i;
int main(){
	while(EOF!=scanf("%ld",&k)){
		b=b1=0;
		for(n=k;n>0;n>>=1){b1+=n%2;++b;}
		for(n=k,i=0;n>1;n>>=1,++i)
			if(n%2)printf("CALL %ld\n",b+b1-2-i);
		for(i=1;i<b;++i)printf("CALL %ld\n", b1+i-1);
		puts("BELL&RET\n");
	}
}
