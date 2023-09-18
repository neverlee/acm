#include<stdio.h>
int main(){
    char a,b=0;int max,len;
    while(EOF!=(a=getchar())){
        if(a==10){
            b=0;
            max=max>len?max:len;
            printf("%ld\n",max);
            max=0;
        }else if(a==b){
            ++len;
        }else if(b==0){
            b=a;len=max=1;
        }else{
            max=max>len?max:len;
            len=1;
            b=a;
        }
    }
    return 0;
}