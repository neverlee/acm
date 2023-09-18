// 11017-Oulipo.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<cstdio>
#include<cstring>
const int MSRC = 1000010L;
const int MTG = 100010L;
char str[MSRC], substr[MTG];
int ncase, next[MTG];

void getNext(char *tg, int *next, int len){
	int i=0, j=-1; next[0]=-1;
	while(i<len){
		if(j<0 || tg[i]==tg[j]){
			++i;++j;
			if(tg[i]!=tg[j]) next[i]=j;
			else next[i]=next[j];
		}
		else{j=next[j];}
	}
}

int getNum(char *str, char *substr){
	int slen, sslen, have=0;
	slen=strlen(str); sslen=strlen(substr);
	getNext(substr, next, sslen);
	for(int i=0,j=0; i<slen&&j<=sslen;){
		if(j==-1|| str[i]==substr[j]){++i;++j;}
		else j=next[j];
		if(j>=sslen){++have;}
	}
	return have;
}

int main(){
	scanf("%ld",&ncase);
	while(ncase--){
		scanf("%s",substr);
		scanf("%s",str);
		printf("%ld\n",getNum(str,substr));
	}
	return 0;
}












