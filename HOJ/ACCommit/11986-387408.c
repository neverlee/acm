#include<stdio.h>
int main(){
    char a,b=0;int max=0,len=1;
    while(EOF!=(a=getchar())){
        if(a==10){
            b=0;
            max=max>len?max:len;
            printf("%ld\n",max);
            max=0;len=1;
        }else if(a==b){
            ++len;
        }else{
            max=max>len?max:len;
            len=1;
            b=a;
        }
    }
    return 0;
}