// 10024-积木城堡.cpp : 定义控制台应用程序的入口点。
//

#include<cstdio>
void Word(){
	int house,wood,max;
	scanf("%ld",&house);
	int have[10010]={0};
	char dps[10010]={0};
	for(char the=1;the<=house;++the){
		dps[0]=the;max=0;
		while(1){
			scanf("%ld",&wood);
			if(wood<0)break;
			for(int i=max;i>=0;--i){
				if(dps[i]==the){
					dps[i+wood]=the;
					max=(max>i+wood)?max:(i+wood);
				}
			}
		}
		for(int i=0;i<=max;++i){
			if(dps[i]==the){
				++have[i];
			}
		}
	}
	for(int i=10000;i>=0;--i){
		if(have[i]==house){
			printf("%ld\n",i);
			break;
		}
	}
}
int main(){
	int ncase;
	scanf("%ld",&ncase);
	while(ncase--){
		Word();
	}
	return 0;
}

