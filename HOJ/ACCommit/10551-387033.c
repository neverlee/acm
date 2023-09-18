#include<stdio.h>
#include<string.h>
#include<ctype.h>
int len,i,j;
char str[100];
char mirto[]={"A   3  HIL JM O   2TUVWXY51SE Z  8 "};
int IsPalid(){
    for(i=0,j=len;i<j;++i,--j)if(str[i]!=str[j])return 0;
    return 1;
}
int IsMirror(){
    char res[100];
    int mt;
    for(i=0,j=len;j>=0;++i,--j){
        if(isupper(str[j]))mt=str[j]-\'A\';
        else mt=str[j]-\'0\'+25;
        res[i]=mirto[mt];
    }
    for(i=0;i<=len;++i)if(res[i]!=str[i])return 0;
    return 2;
}

int main(){
    int red;
    while(EOF!=scanf("%s",str)){
        len=strlen(str)-1;
        red=IsPalid()|IsMirror();
        switch(red){
        case 0:printf("%s -- is not a palindrome.",str);break;
        case 1:printf("%s -- is a regular palindrome.",str);break;
        case 2:printf("%s -- is a mirrored string.",str);break;
        case 3:printf("%s -- is a mirrored palindrome.",str);break;
        }
        printf("\n\n");
    }
    return 0;
}