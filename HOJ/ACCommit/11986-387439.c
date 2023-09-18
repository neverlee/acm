#include<stdio.h>
char a,b=0;int m=0,l=1;
int main(){
while(EOF!=(a=getchar())){
if(a==10){
b=0;
m=m>l?m:l;
printf("%ld\n",m);
m=0;l=1;
}else if(a==b){
++l;
}else{
m=m>l?m:l;
l=1;
b=a;
}
}
return 0;
}