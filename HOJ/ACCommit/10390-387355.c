#include<stdio.h>
int iDems[221][11][221];
int iNum,iDiv,iThe;
int i,j,k,m,iMax1, iMax2, iMin;
int IMin(int a,int b){return a<b?a:b;}
int main(){
    scanf("%ld%ld%ld",&iNum,&iDiv,&iThe);
    for(i=1;i<=iNum;++i)iDems[i][1][i]=1;
    for(i=2;i<=iNum;++i){
        iMin=IMin(iDiv, iNum);
        for(j=2 ;j<=iMin;++j){
            iMax1=i/j;
            for(k=1;k<=iMax1;++k){
                iMax2=(i-k)/(j-1);
                for(m=k;m<=iMax2;++m)iDems[i][j][k]+=iDems[i-k][j-1][m];
            }
        }
    }
    m=1;
    for(;iDiv>1;--iDiv){
        for(m;iDems[iNum][iDiv][m]<iThe;++m)
            iThe-=iDems[iNum][iDiv][m];
        printf("%ld ",m);
        iNum-=m;
    }
    printf("%ld\n", iNum);
    return 0;
}