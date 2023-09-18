#include<stdio.h>
#include<string.h>
int iTestCase, iTest, iLength, i;
char sPerm[100];
void GetNext(int iLittle){
    int iBigger;
    char t, *pi, *pj;
    for(iBigger=iLength-1;sPerm[iBigger]<=sPerm[iLittle];--iBigger);
    t=sPerm[iBigger];sPerm[iBigger]=sPerm[iLittle];sPerm[iLittle]=t;
    for(pi=sPerm+iLittle+1;*(pi+1);++pi)
        for(pj=pi+1;*pj;++pj)
            if(*pi>*pj){t=*pi;*pi=*pj;*pj=t;}
}
int main(){
    scanf("%ld", &iTestCase);
    while(iTestCase--){
        scanf("%ld %s", &iTest, sPerm);
        printf("%ld ",iTest);
        iLength=strlen(sPerm);
        for(i=iLength-1;i>0&&sPerm[i]<=sPerm[i-1];i--);
        if(i!=0){
            GetNext(i-1);
            puts(sPerm);
        }else puts("BIGGEST");
    }
    return 0;
}