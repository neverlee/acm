//10734-Hex Factorial.cpp
#include <stdio.h>
int iBit[1000]={1}, iLen=1;
const int SIZE = 201;
int iResult[SIZE]={0};
int main(){
	int i,j,iNum;
	for(i=2;i<SIZE;++i){
		for(j=0;j<iLen;++j)
			iBit[j]*=i;
		for(j=0;j<iLen;++j){
			iBit[j+1]+=iBit[j]/16;
			iBit[j]%=16;
		}
		while(iBit[iLen]){
			iBit[iLen+1]+=iBit[iLen]/16;
			iBit[iLen]%=16;
			++iLen;
		}
		for(int j=0;j<iLen;++j)if(iBit[j]==0)++iResult[i];
	}
	while(scanf("%d",&iNum),iNum>=0)
		printf("%d\n",iResult[iNum]);
}
