#include <stdio.h>
#include <math.h>
int su[10010];
int su2[80010];
void ctoi(int *s,int n)
{
    int i;
    for(i=7;i>=0;i--){
        s[i]=n&1;
        n>>=1;
    }
}

int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n>>3;i++)
        scanf("%d",&su[i]);
    for(i=0,j=0;i<n/8;i++)
    {
        ctoi(su2+j,su[i]);
        j+=8;
    }
    k=1;su2[n]=!su2[n-1];
    for(i=0;i<n;++i)
    {
        if(su2[i]!=su2[i+1]){
            printf("%d ",k|(su2[i]?128:0));
            k=1;
        }else{
            ++k;
        }
    }
    return 0;
}
