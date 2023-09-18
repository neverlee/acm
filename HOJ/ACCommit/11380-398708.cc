#include"cstdio"
int r[1001];
int main(){
    for(int i=1;i<=1000;++i)r[i]=i;
    for(int i=2;i<=1000;++i)r[i]+=r[i-1];
    for(int i=2;i<=1000;++i)r[i]+=r[i-1];
    int t,n;scanf("%d",&t);
    for(int i=1;i<=t;++i){
        scanf("%d",&n);
        printf("%d: %d %ld\n",i,n,r[n]);
    }
}
