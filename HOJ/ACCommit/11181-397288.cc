#include<cstdio>
#include<ctype.h>

const int SIZE = 19683;
const int ADD = 757;
int iMsgAmount,iaKey[4],iMsg;
int GetStr(){
    int code, src;
    for(int i=0;i<SIZE;++i){
        code=0;
        src=(i/729+1)*10000 + (i%729/27+1)*100 + i%27+1;
        for(int j=0;j<4;++j)
            code=code*100+src%iaKey[j];
        if(code==iMsg)return i;
    }
}
char sResult[400];int len;
int main(){
    int iTest;scanf("%ld",&iTest);
    int iRs;
    while(iTest--){
        len=0;
        scanf("%ld",&iMsgAmount);
        for(int i=0;i<4;++i)scanf("%ld",iaKey+i);
        while(iMsgAmount--){
            scanf("%ld",&iMsg);
            iRs=GetStr();
            sResult[len]=iRs/729;
            sResult[len+1]=iRs%729/27;
            sResult[len+2]=iRs%27;
            for(int i=len;i<len+3;++i){
                if(sResult[i]<26)sResult[i]+=65;
                else sResult[i]=\' \';
            }
            len+=3;
        }
        sResult[len]=0;
        for(int i=len-1;i>=0&&sResult[i]==\' \';--i)
            sResult[i]=0;
        puts(sResult);
    }
}
