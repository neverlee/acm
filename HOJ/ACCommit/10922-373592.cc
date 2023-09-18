#include<cstdio>
__int64 a[51]={0};
__int64 left(__int64 N,__int64 M){
    __int64 N1=1,M1=1;
    while(N1<=N)N1*=10;
    while(M1<=M)M1*=10;
    if((N*M1+M)<(M*N1+N))return 1;
    return 0;
}
int main(){
    int N, i, j, temp;
    while (scanf("%d",&N),N != 0){
        for(i=0;i<N;i++)scanf("%I64d",&a[i]);
        for(i=0;i<N-1;i++)
            for(j=i+1;j<N;j++)
                if(left(a[i],a[j])){
                    temp=a[i];a[i]=a[j];a[j]=temp;
                }
        for(i=0;i<N;i++)printf("%I64d",a[i]);
        printf("\n");
    }
    return 0;
}