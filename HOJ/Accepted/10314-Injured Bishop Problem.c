//10314-Injured Bishop Problem.c
#include<stdio.h>
#include<math.h>
int iTestCase, iTest, ix1,iy1,ix2,iy2,iDm;
int IMax(int a,int b){return a>b?a:b;}
int main(){
	scanf("%ld",&iTestCase);
	for(iTest=1;iTest<=iTestCase;++iTest){
		scanf("%ld",&iDm);
		scanf("%ld%ld%ld%ld",&ix1,&iy1,&ix2,&iy2);
		printf("Case %ld:\n",iTest);
		if((abs(ix1-ix2)+abs(iy1-iy2))%2){
			printf("-1\n");
		}else{
			printf("%ld\n",IMax(abs(ix1-ix2),abs(iy1-iy2)));
		}
		if(iTest!=iTestCase)putchar('\n');
	}
	return 0;
}