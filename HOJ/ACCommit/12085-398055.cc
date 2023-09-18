#include<cstdio>
int grid[1025][1025],n;
int x1,y1,x2,y2;
char o;
void Init(){
    for(int i=0;i<=1024;++i)grid[i][0]=grid[0][i]=0;
    for(int i=1;i<=1024;++i)
    for(int j=i%2;j<=1024;j+=2)
            grid[i][j]=1;
    for(int i=1;i<=1024;++i)
    for(int j=1;j<=1024;++j)
        grid[i][j]+=grid[i][j-1];
}
int main(){
    int sa,sb;
    Init();
    scanf("%ld%*c",&n);
    while(n--){
        scanf("%c %ld %ld%*c", &o, &x1, &y1);
        switch(o){
        case \'R\':
            scanf("%ld %ld%*c",&x2,&y2);
            sa=sb=0;
            for(int i=x1;i<=x2;++i)
                sa+=(grid[i][y2]-grid[i][y1-1]);
            sb=(x2-x1+1)*(y2-y1+1)-sa;
            printf("%ld %ld\n",sa,sb);
            break;
        case \'A\':
            if(grid[x1][y1]-grid[x1][y1-1]==0)
            for(int i=y1;i<=1024;++i)++grid[x1][i];break;
        case \'B\':
            if(grid[x1][y1]-grid[x1][y1-1]==1)
            for(int i=y1;i<=1024;++i)--grid[x1][i];break;
        }
    }
}
