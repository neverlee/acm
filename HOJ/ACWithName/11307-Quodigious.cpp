//11307-Quodigious.cpp
#include<cstdio>
int res[10][200],len[10]={0};
void Init(){
	int start=0,end=1;
	int add, mul, temp, k;bool flag;
	for(int i=1;i<8;++i){
		start=start*10+2;end=end*10;
		for(int j=start;j<end;++j){
			temp=j;add=0;mul=1;temp=j;flag=1;
			while(temp){
				k=temp%10;temp/=10;
				if(k>1){
					add+=k;mul*=k;
				}else{
					flag=0;
					break;
				}
			}
			if(flag&&!(j%add||j%mul))
				res[i][len[i]++]=j;
		}
	}
}
int main(){
	Init();
	int num;
	while(scanf("%ld",&num)!=EOF){
		for(int i=0;i<len[num];++i){
			printf("%ld\n",res[num][i]);
		}
		printf("\n");
	}
	return 0;
}