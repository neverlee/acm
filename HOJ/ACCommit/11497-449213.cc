#include<cstdio>
#include<cstring>
char mx[1000][1000];
bool flag;
int main() {
    int i,j,k,section,x[2],y[2];
    while(~scanf("%d",§ion)) {
        memset(mx,0,sizeof(mx));
        flag=0;
        for(i=0;i<section;i++) {
            scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
                for(j=x[0];j<=x[1] && !flag;j++)
                    for(k=y[0];k<=y[1] && !flag;k++)
                        if(!mx[j][k])
                            mx[j][k]=1;
                        else
                            flag=1;
        }
        puts(flag?"Overlap":"No Overlap");
    }
    return 0;
}