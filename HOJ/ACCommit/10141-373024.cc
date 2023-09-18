#include<cstdio>
#include<cstring>
char tok[100],str[1000];

int main(){
    gets(tok);
    str[0]=0;
    while(gets(str+1)){
        int len=strlen(str+1);
        for(char *p=strtok(str+1, tok);p;p=strtok(NULL, tok))puts(p);
        puts("END");
    }
}