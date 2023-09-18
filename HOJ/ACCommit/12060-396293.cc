#include<cstdio>
char str[100];
int y,n,a,p,l;
int main(){
    while(scanf("%s",str),str[0]!=\'#\'){
        y=n=a=p=0;
        for(l=0;str[l];++l){
            if(str[l]==\'A\')++a;
            else if(str[l]==\'Y\')++y;
            else if(str[l]==\'N\')++n;
            else if(str[l]==\'P\')++p;
        }
        l=(l>>1)+(l&1);
        if(a>=l)printf("need quorum\n");
        else if(y>n)printf("yes\n");
        else if(n>y)printf("no\n");
        else if(y==n)printf("tie\n");
    }
}
