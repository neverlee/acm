//11456-The Composition of Letters.c   wa
#include<stdio.h>
int test,count,total;
char use[50],word[50];
int len, syb[50], pr=0, pre, have;
void Answer(int sum, int pos){
	int i;
	if(sum==total){
		for(i=0,len=0;i<pos;++i)if(use[i])putchar(syb[i]+'A'-1);
		putchar('\n');
		++have;
	}
	if(sum<total&&pos<count){
		use[pos]=1;
		if(pre!=syb[pos]){
			pre=0;
			Answer(sum+syb[pos], pos+1);
		}
		use[pos]=0;
		pre=syb[pos];
		Answer(sum, pos+1);
	}
}
int main(){
	int t,i;
	scanf("%ld",&test);
	for(t=1;t<=test;++t){
		printf("Case %ld\n",t);
		scanf("%ld",&count);
		for(i=0;i<count;++i){
			getchar();
			syb[i]=getchar()-'A'+1;
			use[i]=0;
		}
		total=0;
		scanf("%s",word);
		for(len=0;word[len];++len)total+=(word[len]-'A'+1);
		pre=0;have=0;
		Answer(0, 0);
		if(count==0)printf("NONE\n");
	}
	return 0;
}