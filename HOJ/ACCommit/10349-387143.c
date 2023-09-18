#include<stdio.h>
int main(){
    int i,j,have;
    char str[1000];
    while(gets(str)){
        for(i=0;str[i];){
            if(str[i]==str[i+1]){
                have=1;
                while(str[i]&&str[i]==str[i+1]){++have;++i;if(have==9)break;}
                printf("%ld%c",have,str[i]);
                ++i;
            }else{
                putchar(\'1\');
                while(str[i]&&str[i]!=str[i+1]){
                    putchar(str[i]);
                    if(str[i]==\'1\')putchar(\'1\');
                    ++i;
                }
                putchar(\'1\');
            }
        }
        putchar(\'\n\');
    }
    return 0;
}