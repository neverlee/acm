#include<cstdio>
int main(){
    int num;
    while(scanf("%ld",&num),num){
        printf("%ld => %ld\n",num,num*num-num+1);
    }
    return 0;
}