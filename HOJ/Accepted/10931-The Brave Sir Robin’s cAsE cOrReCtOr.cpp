//10931-The Brave Sir Robin's cAsE cOrReCtOr.cpp
#include<cstdio>
#include<ctype.h>
char str[10000], flag;
int main(){
	flag=0;
	while(gets(str)){
		for(int i=0;str[i];++i){
			if(str[i]=='.'||str[i]=='?'||str[i]=='!')flag=1;
			else if(str[i]==' '||str[i]=='('||str[i]==')');
			else{
				if(flag==0){
					if(isupper(str[i]))str[i]+=32;
				}else{
					if(islower(str[i]))str[i]-=32;
					flag=0;
				}
			}
			putchar(str[i]);
		}
		putchar('\n');
	}
}
