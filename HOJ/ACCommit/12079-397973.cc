#include<cstdio>
#include<cstring>
int c,n,m,f[2][100010],t;
int Max(int a,int b){return a>b?a:b;}
void Dp(){
    int pp=0,pr=1;
    for(int i=0;i<m;++i)f[0][i]=f[1][i]=0;
    f[1][0]=1;
    while(n--){
        pr=pp;pp=1-pp;
        scanf("%ld",&t);
        for(int i=0;i<m;++i)f[pr][i]=f[pp][i];
        for(int i=0;i<m;++i){
            if(f[pp][i])
                f[pr][(i+t)%m]=Max(f[pp][(i+t)%m], f[pp][i]+1);
        }
    }
    printf("%ld\n", f[pr][0]-1);
}
int main(){
    scanf("%ld",&c);
    while(c--){
        scanf("%ld%ld",&n,&m);
        Dp();
    }
}
