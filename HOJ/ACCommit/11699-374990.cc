#include<cstdio>
int t,w,b;
int main(){
    scanf("%ld",&t);
    while(t--){
        scanf("%ld%ld",&w,&b);
        if(w%2)printf("WhiteBall\n");
        else printf("BlackBall\n");
    }
    return 0;
}