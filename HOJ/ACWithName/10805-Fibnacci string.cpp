//10805-Fibnacci string.cpp
#include<cstdio>
#include<cstring>
char sForm[3000000], str[1000000];
int len[100]={1,1}, pos[100], isz, sl;
int main(){
	for(isz=2;(len[isz]=len[isz-1]+len[isz-2])<=1000000;++isz);
	pos[0]=0;
	for(int i=1;i<isz;++i)pos[i]=pos[i-1]+len[i-1]+1;
	sForm[pos[0]]='b';sForm[pos[1]]='a';
	for(int i=2;i<isz;++i){
		strcpy(sForm+pos[i], sForm+pos[i-1]);
		strcpy(sForm+pos[i]+len[i-1], sForm+pos[i-2]);
	}
	while(gets(str),str[0]!='0'){
		sl=strlen(str);
		int i;
		for(i=0;i<isz;++i){
			if(sl==len[i]&&strcmp(str, sForm+pos[i])==0){
				printf("true\n");
				break;
			}
		}
		if(i==isz)printf("false\n");
	}
	return 0;
}
