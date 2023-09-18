#include<cstdio>
#include<ctype.h>
char refer[27]=" d b    i     oqp    vwx  ", str[1000];
char Mirror(){
    int l;
    for(l=0;str[l];++l){
        if(islower(str[l])){
            if(refer[str[l]-\'a\']==\' \')return 0;
            else str[l]=refer[str[l]-\'a\'];
        }else return 0;
    }
    for(--l;l>=0;l--)putchar(str[l]);
    putchar(\'\n\');
    return 1;
}
int main(){
    while(gets(str),str[0]!=\'#\'){
        if(!Mirror())printf("INVALID\n");
    }
}
