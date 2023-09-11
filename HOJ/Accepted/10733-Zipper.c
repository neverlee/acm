//10733-Zipper.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str1[210],str2[210],strgroup[410];
int iTestCase,iTest;
char cgDp[210][210];
void Dp();
int main(){
	str1[0]=str2[0]=strgroup[0]=0;
	scanf("%ld",&iTestCase);
	for(iTest=1;iTest<=iTestCase;++iTest){
		printf("Data set %ld: ",iTest);
		scanf("%s%s%s",str1+1,str2+1,strgroup+1);
		Dp();
	}
    return 0;
}
void Dp(){
	int i,j;
	cgDp[0][0]=1;
	for(i=1;str1[i];++i)
		if(cgDp[i-1][0]&&str1[i]==strgroup[i])cgDp[i][0]=1;
	for(i=1;str2[i];++i)
		if(cgDp[0][i-1]&&str2[i]==strgroup[i])cgDp[0][i]=1;
	for(i=1;str1[i];++i)
		for(j=1;str2[j];++j){
			if((str1[i]==strgroup[i+j]&&cgDp[i-1][j])
				||(str2[j]==strgroup[i+j]&&cgDp[i][j-1]))
					cgDp[i][j]=1;
			else cgDp[i][j]=0;
		}
	if(cgDp[i-1][j-1])printf("yes\n");
	else printf("no\n");
}
