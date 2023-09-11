//10469-变换图案.c
#include<stdio.h>
char src[101][101], tag[101][101] ,mir[101][101];
int len;
char CkSrc(char src[101][101]){
	int i,j;
	for(i=0;i<len;++i)for(j=0;j<len;++j)
		if(src[i][j]!=tag[i][j])return 0;
	return 1;
}
char CkRt90(char src[101][101]){
	int i,j;
	for(i=0;i<len;++i)for(j=0;j<len;++j)
		if(src[i][j]!=tag[j][len-1-i])return 0;
	return 1;
}
char CkRt180(char src[101][101]){
	int i,j;
	for(i=0;i<len;++i)for(j=0;j<len;++j)
		if(src[i][j]!=tag[len-1-i][len-1-j])return 0;
	return 1;
}
char CkRt270(char src[101][101]){
	int i,j;
	for(i=0;i<len;++i)for(j=0;j<len;++j)
		if(src[i][j]!=tag[len-1-j][i])return 0;
	return 1;
}
char GetMir(){
	int i,j;
	for(i=0;i<len;++i)for(j=0;j<len;++j)mir[len-1-i][j]=src[i][j];
	for(i=0;i<len;++i)for(j=0;j<len;++j)
		if(mir[i][j]!=tag[i][j])return 0;
	return 1;
}
void Check(){
	if(CkSrc(src)){
		printf("idt\n");return;
	}else if(CkRt90(src)){
		printf("rot90\n");return;
	}else if(CkRt180(src)){
		printf("rot180\n");return;
	}else if(CkRt270(src)){
		printf("rot270\n");return;
	}else if(GetMir()){
		printf("vr\n");return;
	}else if(CkSrc(mir)){
		printf("vr\n");return;
	}else if(CkRt90(mir)){
		printf("vr-rot90\n");return;
	}else if(CkRt180(mir)){
		printf("vr-rot180\n");return;
	}else if(CkRt270(mir)){
		printf("vr-rot270\n");return;
	}
	printf("imp\n");
}
int main(){
	int i,j,test=0;
	while(EOF!=scanf("%ld%*c",&len)){
		for(i=0;i<len;++i){
			for(j=0;j<=len;++j)src[i][j]=getchar();
			for(j=0;j<=len;++j)tag[i][j]=getchar();
		}
		printf("%ld ",++test);
		Check();
	}
	return 0;
}