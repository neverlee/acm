#include<cstdio>
#include<cstring>
char str[1020];int len,re;
int main(){
    while(EOF!=scanf("%s",str)){
        re=len=strlen(str);
        int i,j=0;
        for(i=0;i<len-1;i++){
            if(str[i]==\'<\')    {
                if(j<=i)j=i+1;
                while(str[j]!=\'>\'&&j<len)j++;
                if(j==len)break;
                str[i]=str[j]=0;re-=2;
            }
        }
        printf("%ld\n",re);
    }
    return 0;
}
