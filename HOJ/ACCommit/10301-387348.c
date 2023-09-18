#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct __TSNumber{
    int iNum, iIncrease
}TSNumber;
TSNumber tsNumber[1010];
int iOutAmount, iRegister, iTotal[1010];
int Compare(void *va, void *vb){
    return ((TSNumber*)va)->iNum-((TSNumber*)vb)->iNum;
}
void Result(){
    int i,iPos,iMin;
    while(iOutAmount--){
        iPos=0;iMin=iTotal[0];
        for(i=1;i<iRegister;++i){
            if(iMin>iTotal[i]){
                iMin=iTotal[i];
                iPos=i;
            }
        }
        printf("%ld\n", tsNumber[iPos].iNum);
        iTotal[iPos]+=tsNumber[iPos].iIncrease;
    }
}
int main(){
    int i;
    char str[100];
    for(iRegister=0;gets(str);++iRegister){
        if(str[0]==\'#\')break;
        sscanf(str+8, "%ld%ld", &tsNumber[iRegister].iNum
                , &tsNumber[iRegister].iIncrease);
    }
    qsort(tsNumber, iRegister, sizeof(TSNumber), Compare);
    for(i=0;i<iRegister;++i)
        iTotal[i]=tsNumber[i].iIncrease;
    scanf("%ld%*c",&iOutAmount);
    Result();
    return 0;
}
