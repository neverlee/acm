#include<stdio.h>
char rect[729][730];
void InitSpace(){
    int i,j;
    for(i=0;i<729;++i){
        for(j=0;j<729;++j)rect[i][j]=\' \';
        //rect[i][729]=0;
    }
}
void Copy(int sx, int sy, int len){
    int i,j;
    for(i=0;i<len;++i)
        for(j=0;j<len;++j)
            rect[sx+i][sy+j]=rect[i][j];
}
void Create(){
    int i,k;
    rect[0][0]=\'X\';
    for(i=1;i<729;i*=3){
        k=i<<1;
        Copy(0, k, i);
        Copy(i, i, i);
        Copy(k, 0, i);
        Copy(k, k, i);
    }
    for(i=0;i<729;++i){
        k=728;
        while(rect[i][k]==\' \')--k;
        rect[i][k+1]=0;
    }
}
void Output(int pos){
    int s=729>>1, len=1, i;
    for(i=1;i<pos;++i){
        s-=len;
        len*=3;
    }
    for(i=s;i<s+len;++i)
        puts(rect[i]+s);
    puts("-");
}
int main(){
    int num;
    InitSpace();
    Create();
    while(scanf("%ld",&num),num!=-1){
        Output(num);
    }
    return 0;
}