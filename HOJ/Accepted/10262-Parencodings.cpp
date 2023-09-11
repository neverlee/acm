//10262-Parencodings.cpp
#include<cstdio>
#include<cstring>
char pare[40];
int c, n, t;
int main(){
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        memset(pare, 0, sizeof(pare));
        for(int i=1;i<=n;++i){
            scanf("%d",&t);
            pare[(t+=i)]=1;
            for(int j=t-1,k=1;j>=0;--j){
                if(pare[j]==0){
                    pare[j]=-1;
                    printf("%d",k);
                    break;
                }else if(pare[j]==-1)++k;
            }
            if(i!=n)putchar(' ');
            else putchar('\n');
        }
    }
}