#include<stdio.h>
#include<math.h>
int CPrime[400]={2,3},CLen;//168
int count[400],num,kmod;
char IsCPrime(int n){
    int i,len=(int)sqrt((double)n);
    for(i=0;CPrime[i]<=len;++i)
        if(n%CPrime[i]==0)return 0;
    return 1;
}
void InitCloud(){
    int i;CLen=2;
    for(i=5;i<2020;i+=2)
        if(IsCPrime(i))CPrime[CLen++]=i;
}
void SetCount(int tm, int style){
    int i;
    for(i=0;tm>=CPrime[i];++i){
        while(tm%CPrime[i]==0){
            count[i]+=style;
            tm/=CPrime[i];
        }
    }
}
int main(){
    int i,result;
    InitCloud();
    while(EOF!=scanf("%ld%ld",&num,&kmod)){
        count[0]=num>>1;
        for(i=1;i<CLen;++i)count[i]=0;
        for(i=num*2-1;i>num+1;i-=2)SetCount(i,1);
        for(i=2;i<=(num+1)>>1;++i)SetCount(i,-1);
        result=1;
        for(i=0;i<CLen;++i){
            while(count[i]--){
                result=(result*CPrime[i])%kmod;
            }
        }
        printf("%ld\n",result%kmod);
    }
    return 0;
}