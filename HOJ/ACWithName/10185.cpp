//10185
#include<stdio.h>
int main(){
	int count,i,j,m,a,sum,s,no;
	scanf("%ld",&count);
	while(count--){
		no=1;scanf("%ld",&a);m=a/2;
		for(i=1;i<=m;++i){
			for(sum=0,j=i;sum<a;++j)sum+=j;
			if(sum==a){
				printf("%ld",i);
				for(s=i+1;s<j;++s)printf(" %ld",s);
				printf("\n");
				no=0;
			}
		}
		if(no)printf("NONE\n");
	}
	return 0;
}