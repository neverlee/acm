//11248-Decoding.cpp
#include<cstdio>
#include<cstring>
char str[1000], rect[5000];
int row, col;
void SetK(int k, char m){
	str[k/5]=(str[k/5]<<1)+(m-'0');
}
void FromRect(){
	int r=0,c=0,er=row-1,ec=col-1,k=0,i;
	for(;r<=er&&c<=ec;++r,++c,--er,--ec){
		for(i=c;i<=ec;++i)SetK(k++, rect[r*col+i]);
		for(i=r+1;i<=er;++i)SetK(k++, rect[i*col+ec]);
		if(er-r>0)for(i=ec-1;i>=c;--i)SetK(k++, rect[er*col+i]);
		if(ec-c>0)for(i=er-1;i>r;--i)SetK(k++, rect[i*col+c]);
	}
	r=k/5;
	for(i=0;i<=r;++i)if(str[i])str[i]+=64;else str[i]=' ';
	for(i=r;i>=0&&str[i]==' ';--i)str[i]=0;
}
int main(){
	int iTest;scanf("%ld",&iTest);
	for(int iCase=1;iCase<=iTest;++iCase){
		memset(str,0,sizeof(str));
		scanf("%ld %ld %s",&row,&col,rect);
		FromRect();
		printf("%ld %s\n",iCase, str);
	}
	return 0;
}

