#include<cstdio>
#include<cmath>
int b,n;double k;
int main(){
    while(scanf("%ld%ld",&b,&n),b){
        k=log10((double)b)*n;
        k-=(int)k;
        printf("%ld\n",(int)pow(10.0, k));
    }
}
