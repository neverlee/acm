//11689-Magic Tree.c
#include<stdio.h>
int iFoot, iFall[1010];
int iDp[40][1010], iTime;
void Input(){
	int iTemp, i;
	iFall[0]=1;
	iFall[1]=0;
	while(iTime--){
		scanf("%ld",&iTemp);
		if(iTemp%2==iFall[0]%2)++iFall[iFall[0]];
		else iFall[++iFall[0]]=1;
	}
}
int IMax(int ia, int ib){return ia>ib?ia:ib;}
void Dp(){
	int i,j,iMax;
	iDp[0][0]=-1;
	iDp[0][1]=iFall[1];
	iDp[0][2]=iFall[2];
	iMax=IMax(iFall[1],iFall[2]);
	for(i=3;i<=iFall[0];++i){
		iDp[0][i]=iDp[0][i-2]+iFall[i];
		iMax=IMax(iDp[0][i],iMax);
	}
	for(i=1;i<=iFoot;++i){
		iDp[i][i-1]=iDp[i][i]=-1;
		for(j=i+1;j<=iFall[0];++j){
			if(iDp[i-1][j-1]==-1&&iDp[i][j-2]==-1)iDp[i][j]=-1;
			else iDp[i][j]=IMax(iDp[i-1][j-1],iDp[i][j-2])+iFall[j];
			iMax=IMax(iDp[i][j],iMax);
		}
	}
	printf("%ld\n",iMax);
}
int main(){
	while(EOF!=scanf("%ld%ld",&iTime,&iFoot)){
		Input();
		Dp();
	}
	return 0;
}
