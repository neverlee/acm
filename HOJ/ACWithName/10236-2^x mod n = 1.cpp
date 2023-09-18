//10236-2^x mod n = 1.cpp
#include<cstdio>
unsigned __int64 k;
int num,i;
int main(){
	while(EOF!=scanf("%ld",&num)){
		if(num==1){
			printf("2^? mod 1 = 1\n");
			continue;
		}
		if(num&1==0){
			printf("2^? mod %ld = 1\n",num);
			continue;
		}
		k=2;
		for(i=2;i<=num+1;++i){
			k=(k<<1)%num;
			if(k==1){
				printf("2^%ld mod %ld = 1\n",i,num);
				break;
			}
		}
		if(i==num+2)printf("2^? mod %ld = 1\n",num);
	}
	return 0;
}
