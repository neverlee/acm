#include<stdio.h>
int test, num;
int queue[15], top, size;
void Insert(int ele){
    int i;
    for(i=size;i>top;--i)
        queue[i]=queue[i-1];
    queue[top]=ele;
    ++size;
}
void Move(int foot){
    while(foot--){
        --top;
        if(top<0)top=size-1;
    }
}
void GetResult(){
    int i;
    queue[0]=num;
    top=0;size=1;
    for(i=num-1;i>0;--i){
        Insert(i);
        Move(i);
    }
    printf("%ld",queue[top]);
    for(i=1;i<size;++i)
        printf(" %ld",queue[(top+i)%size]);
    putchar(\'\n\');
}
int main(){
    scanf("%ld",&test);
    while(test--){
        scanf("%ld",&num);
        GetResult();
    }
    return 0;
}