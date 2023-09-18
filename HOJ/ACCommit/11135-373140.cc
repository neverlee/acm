#include<cstdio>
int main(){
    int n,k,t;
    while(scanf("%d%d",&n,&k),n||k){
        t=k;
        while(n/t>=k)t*=k;
        k=n/t;
        printf("%d\n%d",k,t);
        for(int i=2;i<=k;++i){
            printf(" %d",t*i);
        }
        printf("\n");
    }
    return 0;
}