#include<cstdio>
char rect[110][110]={0};
char temp;
char pos[8][2]={-1,-1, -1,0, -1,1, 0,-1, 0,1, 1,-1, 1,0, 1,1};
int hi,wd;
int main(){
	int text;
	for(text=1;;text++){
		scanf("%ld%ld",&hi,&wd);
		if(hi&&text!=1)putchar('\n');
		if(hi==0)return 0;
		for(int i=1;i<=hi;i++){
			scanf("%s",rect[i]+1);
		}
		for(int i=1;i<=wd+1;i++){
			rect[hi+1][i]=0;
		}
		printf("Field #%ld:\n",text);
		for(int i=1;i<=hi;i++){
			for(int j=1;j<=wd;j++){
				if(rect[i][j]=='.'){
					int total=0;
					for(int k=0;k<8;k++){
						temp=rect[i+pos[k][0]][j+pos[k][1]];
						if(temp=='*')++total;
					}
					rect[i][j]='0'+total;
				}
			}
			printf("%s\n",rect[i]+1);
		}
	}
}