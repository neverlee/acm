#include<cstdio>
#include<cstring>
int prime[10001]={1,1}, len=2;
int iaDp[10001];
void Init(){
    for(int i=2; i<10001; ++i)
        if(0==prime[i])
            for(int t=i*i; t<10001; t+=i)
                prime[t]=1;
    prime[0]=0;prime[1]=2;
    for(int i=3;i<10000;i+=2)
        if(prime[i]==0)prime[len++]=i;
}
void Dp(){
    int k;
    for(int i=1;i<len;++i)prime[i]+=prime[i-1];
    for(int i=1;i<len;++i)
        for(int j=i;j<len;++j){
            k=prime[j]-prime[j-i];
            if(k>10000)break;
            ++iaDp[k];
        }
}
int main(){
    int iCase, iNum;
    Init();
    Dp();
    scanf("%ld",&iCase);
    while(iCase--){
        scanf("%ld",&iNum);
        printf("%ld\n",iaDp[iNum]);
    }
}
