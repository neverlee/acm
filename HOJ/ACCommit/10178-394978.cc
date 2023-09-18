#include<cstdio>
int main(){
    int a,b,c,n;
    scanf("%ld",&n);
    while(n--){
        scanf("%ld%ld",&a,&b);
        while(b){c=a%b;a=b;b=c;}
        printf("%ld\n",a);
    }
    return 0;
}