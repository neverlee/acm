//10180-找最大的正方形.cpp
#include<cstdio>
const short SIZE = 501;
bool map[SIZE][SIZE]={0};
short rect[SIZE][SIZE]={0};
short len, num, max;
short min(short a,short b,short c){
	if(a>b)a=b;
	if(a>c)a=c;
	return a;
}
int main(){
	scanf("%d%d",&len,&num);
	for(short i=0;i<=len;++i){
		map[0][i]=map[i][0]=1;
	}
	int x,y;
	while(num--){
		scanf("%d%d",&x,&y);
		map[x][y]=1;
	}
	max=0;
	for(short i=1;i<=len;++i){
		for(short j=1;j<=len;++j){
			if(map[i][j])continue;
			rect[i][j]=min(rect[i-1][j],rect[i][j-1],rect[i-1][j-1])+1;
			max=rect[i][j]>max?rect[i][j]:max;
		}
	}
	printf("%d\n",max);
	return 0;
}