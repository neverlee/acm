//10795-Wildcard Characters.c
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char asStr[1010][12], sPattern[20];
int iaStrLen[1010];
int iStringAmount, iPatternAmount, iSameAmount;
void DealPattern(){
	int i=0, j, iStar, iAsk;
	for(i=0;sPattern[i];){
		if(sPattern[i]=='*'||sPattern[i]=='?'){
			iStar=iAsk=0;
			for(j=i;sPattern[j]=='*'||sPattern[j]=='?';++j){
				if(sPattern[j]=='*')++iStar;
				if(sPattern[j]=='?')++iAsk;
			}
			for(;iAsk--;++i)sPattern[i]='?';
			if(iStar)sPattern[i++]='*';
			strcpy(sPattern+i, sPattern+j);
		}else ++i;
	}
	for(i=0;sPattern[i];++i)
		if(islower(sPattern[i]))sPattern[i]-=32;
}
int iPatternLen, iRecent;
char Check(int ipp, int isp){
	char red=0;
	int i;
	if(ipp==iPatternLen&&iaStrLen[iRecent]==isp)return 1;
	while(sPattern[ipp]==asStr[iRecent][isp]||sPattern[ipp]=='?'){
		++ipp;++isp;
		if(ipp==iPatternLen&&iaStrLen[iRecent]==isp)return 1;
		if((ipp==iPatternLen||iaStrLen[iRecent]==isp)&&sPattern[ipp]!='*')return 0;
	}
	if(sPattern[ipp]=='*')
	for(i=isp;i<=iaStrLen[iRecent];++i)
		red|=Check(ipp+1, i);
	return red;
}
int main(){
	int i,j;
	scanf("%ld",&iStringAmount);
	for(i=0;i<iStringAmount;++i){
		scanf("%s",asStr[i]);
		iaStrLen[i]=strlen(asStr[i]);
		for(j=0;j<iaStrLen[i];++j)
			if(islower(asStr[i][j]))asStr[i][j]-=32;
	}
	scanf("%ld",&iPatternAmount);
	for(i=0;i<iPatternAmount;++i){
		iSameAmount=0;
		scanf("%s",sPattern);
		DealPattern();
		iPatternLen=strlen(sPattern);
		for(j=0;j<iStringAmount;++j){
			iRecent=j;
			iSameAmount+=Check(0,0);
		}
		printf("%ld\n",iSameAmount);
	}
	return 0;
}