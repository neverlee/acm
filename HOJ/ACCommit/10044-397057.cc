#include<cstdio>
int main(){int k,b,o,n,i;while(EOF!=scanf("%d",&k)){b=o=0;for(n=k;n>0;n>>=1){o+=n%2;++b;}for(n=k,i=0;n>1;n>>=1,++i)if(n%2)printf("CALL %d\n",b+o-2-i);for(i=1;i<b;++i)printf("CALL %d\n", o+i-1);puts("BELL&RET\n");}}