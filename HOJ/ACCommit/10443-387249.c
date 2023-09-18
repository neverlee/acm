#include<stdio.h>
int iDim, iTotal, iTmp;
int main(){
    scanf("%ld %ld",&iDim, &iTotal);
    --iTotal;
    while(iDim--){
        scanf("%ld",&iTmp);
        printf("%ld",iTotal/iTmp);
        iTotal%=iTmp;
        if(iDim)putchar(\' \');
    }
    return 0;
}