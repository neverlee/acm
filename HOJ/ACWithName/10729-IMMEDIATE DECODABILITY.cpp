//10729-IMMEDIATE DECODABILITY.cpp
#include<cstdio>
#include<cstring>
typedef unsigned char uchar;
uchar tree[2048];
char str[20];
bool flag;
int iBit;
enum{
	left=1, right=2, all=3, used=4
};
int main(){
	memset(tree, 0, sizeof(tree));
	flag=1;
	for(int iTest=0;EOF!=scanf("%s",str);){
		if(str[0]=='9'){
			printf("Set %ld is ", ++iTest);
			if(flag)puts("immediately decodable");
			else puts("not immediately decodable");
			memset(tree, 0, sizeof(tree));
			flag=1;
		}else{
			if(!flag)continue;
			iBit=1;
			for(int i=0;str[i];++i){
				if(tree[iBit]&used){
					flag=0;break;
				}
				if(str[i]=='0'){
					tree[iBit]|=left;
					iBit<<=1;
				}else{
					tree[iBit]|=right;
					iBit=(iBit<<1)+1;
				}
			}
			if((tree[iBit]&used)||(tree[iBit]&all))flag=0;
			else tree[iBit]|=used;
		}
	}
}
