//11686-Fair Number.cpp
#include<cstdio>
char str[1010];
int len,lf,rg;
int main(){
	while(gets(str),str[0]!='0'){
		for(len=0;str[len];++len){
			if(str[len]>='A'){str[len]-=('A'-10);}
			else str[len]-='0';
		}
		lf=rg=0;
		for(int i=0,j=len-1;i<j;++i,--j){
			lf+=str[i];rg+=str[j];
		}
		if(lf==rg)printf("Y\n");
		else printf("N\n");
	}
	return 0;
}