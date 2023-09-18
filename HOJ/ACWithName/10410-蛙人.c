//10410-蛙人.c
#include<stdio.h>
#define BIGGEST 400000000
int iONeed, iNNeed, iBattleAmount;
int irDp[50][160], iResult=BIGGEST;
int IMin(int a,int b){return a<b?a:b;}
void Dp(){
	int i,j,io,in,iw,ix,iy;
	for(i=0;i<50;++i)
		for(j=0;j<160;++j)irDp[i][j]=BIGGEST;
	irDp[0][0]=0;
	while(iBattleAmount--){
		scanf("%ld%ld%ld",&io,&in,&iw);
		for(i=45-io;i>=0;--i){
			for(j=159-in;j>=0;--j){
				ix=i+io;iy=j+in;
				irDp[ix][iy]=IMin(irDp[ix][iy], irDp[i][j]+iw);
				if(ix>=iONeed&&iy>=iNNeed)iResult=IMin(irDp[i][j]+iw, iResult);
			}
		}
	}
	printf("%ld\n",iResult);
}
int main(){
	scanf("%ld%ld%ld",&iONeed,&iNNeed,&iBattleAmount);
	Dp();
	return 0;
}