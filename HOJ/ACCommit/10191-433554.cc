#include <stdio.h>
int f[20];
int main() {
    int i,j,test;
    f[0]=1;
    for(i=1;i<20;i++)
        for(f[i]=0,j=0;j<i;j++)
            f[i]+=f[j]*f[i-1-j];
    scanf("%d",&test);
    while( test-- ) {
        scanf("%d",&j);
        printf("%d\n",f[j]);
    }
}
