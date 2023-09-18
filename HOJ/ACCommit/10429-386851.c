#include<stdio.h>
char str[1100];
int len;
char Dgs(int st, int ed){
    char l,r;
    if(ed-st==1){
        l=str[st]==\'0\'?\'B\':\'I\';
        putchar(l);
        return l;
    }
    l=Dgs(st, (st+ed)/2);
    r=Dgs((st+ed)/2, ed);
    if(l!=r)l=\'F\';
    putchar(l);
    return l;
}
int main(){
    scanf("%ld%*c", &len);
    gets(str);
    len=1<<len;
    Dgs(0, len);
    return 0;
}