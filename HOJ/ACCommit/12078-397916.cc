#include<cstdio>
int n,d[4],s;
bool IsNice(){
    s=0;
    for(int i=0;i<4;++i)s+=d[i];
    for(int i=0;i<4;++i)if(s==(d[i]<<1))return 1;
    for(int i=1;i<4;++i)if(s==(d[0]+d[i])*2)return 1;
    return 0;
}
bool Occor(){
    int i,k, h[10]={0};
    for(i=0;i<3;++i){
        k=d[i];
        while(k){
            ++h[k%10];
            k/=10;
        }
    }
    for(i=0;h[i]==0;++i);
    k=h[i];
    for(;i<10;++i)
        if(h[i]&&h[i]!=k)return 0;
    return 1;
}
int main(){
    scanf("%ld",&n);
    while(n--){
        scanf("%ld%ld%ld",d,d+1,d+2);
        if(Occor()){
            d[3]=d[2]%100;
            d[2]/=100;
            if(IsNice())puts("yes");
            else puts("no");
        }else puts("no");
    }
}
