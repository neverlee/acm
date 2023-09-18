//10156-Duplicate Words.cpp
#include<cstdio>
#include<map>
#include<string>
using namespace std;
char str[10000];
int main(){
	map<string, bool> tree;
	str[0]=0;
	while(gets(str+1)){
		int len;
		for(len=1;str[len];++len){
			if(str[len]<='Z')str[len]+=32;
			if(str[len]>'z'||str[len]<'a')str[len]=0;
		}
		for(int i=1;i<len;++i){
			if(str[i-1]==0&&(str[i]>='a'&&str[i]<='z')){
				
			}
		}
	}
}