#include<cstdio>
#include<cmath>

int main(){
    int ncase,num;scanf("%ld",&ncase);
    int r;double res,l2=log10(2.0);
    while(ncase--){
        scanf("%ld", &num);
        r=num*l2+1;
        res=pow(10.0, -num*l2+r);
        printf("2^-%ld = %.3lfE-%ld\n", num, res, r);
    }
    return 0;
}
