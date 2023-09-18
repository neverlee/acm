#include<stdio.h>
#include<math.h>
int iHave[2][26], iTotal;
int iTestCase, iTest;
char str[1000];
int main(){
    int i,j;
    scanf("%ld%*c",&iTestCase);
    for(iTest=1;iTest<=iTestCase;++iTest){
        for(i=0;i<26;++i)iHave[0][i]=iHave[1][i]=0;
        for(i=0;i<2;++i){
            gets(str);
            for(j=0;str[j];++j)++iHave[i][str[j]-\'a\'];
        }
        iTotal=0;
        for(i=0;i<26;++i)iTotal+=abs(iHave[0][i]-iHave[1][i]);
        printf("Case #%ld:  %ld\n",iTest, iTotal);
    }
    return 0;
}