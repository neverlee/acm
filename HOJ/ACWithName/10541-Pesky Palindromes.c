//10541-Pesky Palindromes.c
#include<stdio.h>
#include<string.h>
char str[100];
int len,palid[100];
int cklen,result;
char IsPalid(int p){
	char *i,*j;
	for(i=str+p,j=str+p+cklen-1;i<j;++i,--j)if(*i!=*j)return 0;
	return 1;
}
char IsSame(int si,int sj){
	int i,l=(cklen>>1)+1;
	for(i=0;i<l;++i)if(str[si+i]!=str[sj+i])return 0;
	return 1;
}
void GetNow(){
	int i,j,flag;
	for(i=1;i<=palid[0];++i){
		flag=1;
		for(j=i+1;j<=palid[0];++j)
			if(IsSame(palid[i],palid[j])){flag=0;break;}
		result+=flag;
	}
}
void Deal(){
	int i;
	len=strlen(str);
	for(cklen=1;cklen<=len;++cklen){
		palid[0]=0;
		for(i=0;i+cklen<=len;++i)
			if(IsPalid(i))palid[++palid[0]]=i;
		GetNow();
	}
}
int main(){
	while(EOF!=scanf("%s",str)){
		result=0;
		Deal();
		printf("The string '%s' contains %ld palindromes.\n",str,result);
	}
	return 0;
}