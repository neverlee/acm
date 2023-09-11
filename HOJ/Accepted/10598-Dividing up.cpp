// 10598-Dividing up.cpp : 定义控制台应用程序的入口点。
//

#include<cstdio>
int have[7],total,max;
bool dps[500000];
bool CanDiv(){
	if(total%2)return false;
	total/=2;
	dps[0]=1;max=0;
	for(int i=1;i<=total;++i)dps[i]=0;
	for(int i=1;i<7;++i){
		if(!have[i])continue;
		max=max>total?total:max;
		for(int j=max;j>=0;--j){
			if(dps[j]){
				int end=j+i*have[i];
				max=max>end?max:end;
				for(int k=j+i;k<=end&&k<=total;k+=i){
					dps[k]=1;
					if(dps[total])return true;
				}
			}
		}
	}
	return false;
}
int main(){
	for(int test=1;1;test++){
		total=0;
		for(int i=1;i<7;++i){
			scanf("%ld",&have[i]);
			total+=have[i]*i;
		}
		if(total==0)return 0;
		printf("Collection #%ld:\n",test);
		if(CanDiv()){
			printf("Can be divided.\n\n");
		}else{
			printf("Can't be divided.\n\n");
		}
	}
}




