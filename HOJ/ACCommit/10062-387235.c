#include<stdio.h>
int main(){
    long num,result,k,wei;
    while(EOF!=scanf("%ld",&num)){
        if(!num)return 0;
        printf("%ld: ",num);
        result=0;wei=1;
        while(num>0){
            k=num%10;num/=10;
            if(k>4)k--;
            result+=(k*wei);
            wei*=9;
        }
        printf("%ld\n",result);
    }
}
