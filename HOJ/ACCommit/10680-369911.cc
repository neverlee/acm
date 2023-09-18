#include<cstdio>

int gcd(int a, int b){
    int k;
    while(a%b){
        k=a%b;a=b;b=k;
    }
    return b;
}
int result[1010];
void Init(){
    result[0]=0;result[1]=0;int sum=0;
    for(int i=2; i<=1000; i++)
    {
        for(int j=1; j<i; j++)
        if(gcd(i,j)==1)sum++;
        result[i]=sum;
    }
}
int main(){
    int t,lab=1,n;
    Init();
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        printf("%ld %ld %ld\n",lab++,n,result[n]*2+3);
    }
    return 0;
}