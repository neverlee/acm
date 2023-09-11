//12002-The Least Palindromic Number.cpp
#include<cstdio>
#include<cstring>
char str[10010];
int len;
void Deal(){
	int i,j,mid=len>>1;
	i=mid;j=mid+1;
	if(len%2==0)--i;
	for(;i>0;--i,++j){
		if(str[i]>str[j])break;
		else if(str[i]<str[j])i=-1;
	}
	if(i<=0){
		++str[mid];
		for(i=mid;i>0&&str[i]>'9';--i){
			++str[i-1];str[i]='0';
		}
	}
	if(str[0]=='0')i=1;else i=0;
	for(j=len-1;i<j;++i,--j)str[j]=str[i];
	if(str[0]=='0')puts(str+1);
	else puts(str);
}
int main(){
	while(gets(str+1)){
		str[0]='0';
		len=strlen(str);
		Deal();
	}
}
