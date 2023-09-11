#include<stdio.h>
int iTestCase, iTest;
int iRect[110][110], iHigh, iWidth;
void DealRect(){
	int i,j,iMax,iPos;
	for(i=1;i<=iHigh;++i)for(j=1;j<=iWidth;++j)iRect[i][j]=0;
	for(i=1;i<=iWidth;++i){
		while(iRect[0][i]){
			iMax=0;iPos=0;
			for(j=1;j<=iHigh;++j)
				if(iRect[j][i]==0&&iMax<iRect[j][0]){
					iMax=iRect[j][0];
					iPos=j;
				}
			--iRect[iPos][0];
			--iRect[0][i];
			iRect[iPos][i]=1;
		}
	}
}
void Output(){
	int i,j;
	for(i=1;i<=iHigh;++i){
		for(j=1;j<iWidth;++j)
			printf("%ld ",iRect[i][j]);
		printf("%ld\n",iRect[i][iWidth]);
	}
}
int main(){
	int i;
	scanf("%ld",&iTestCase);
	for(iTest=1;iTest<=iTestCase;++iTest){
		scanf("%ld%ld",&iHigh,&iWidth);
		for(i=1;i<=iHigh;++i)scanf("%ld",&iRect[i][0]);
		for(i=1;i<=iWidth;++i)scanf("%ld",&iRect[0][i]);
		//printf("Case %ld:\n",iTest);
		DealRect();
		Output();
	}
	return 0;
}