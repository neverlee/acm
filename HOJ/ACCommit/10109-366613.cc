#include <cstdio>
const short SIZE=200;
const short MAX=32760;
short rect[SIZE][SIZE],high,width;
typedef struct
{short x,y;}Position;
Position queue[40000],go[4]={-1,0,1,0,0,-1,0,1};
int low=0,height=0;
void Init()
{
    char tc;getchar();
    for(int i=1;i<=high;i++)
    {
        for(int j=1;j<=width;j++)
        {
            tc=getchar();
            if(tc==\'0\')
                rect[i][j]=MAX;
            else
            {
                rect[i][j]=0;
                queue[height].x=i;queue[height].y=j;
                ++height;
            }
        }
        getchar();
    }
    for(int i=0;i<=high+1;i++)
        rect[i][0]=rect[i][width+1]=-1;
    for(int i=0;i<=width+1;i++)
        rect[0][i]=rect[high+1][i]=-1;
}

void SetNum()
{
    short t;
    while(low<height)
    {
        for(int i=0;i<4;i++)
        {
            t=rect[queue[low].x+go[i].x][queue[low].y+go[i].y];
            if(t>rect[queue[low].x][queue[low].y]+1)
            {
                queue[height].x=queue[low].x+go[i].x;
                queue[height].y=queue[low].y+go[i].y;
                rect[queue[height].x][queue[height].y]=rect[queue[low].x][queue[low].y]+1;
                ++height;
            }
        }
        ++low;
    }
}

void PutOut()
{
    for(int i=1;i<=high;i++)
    {
        printf("%d",rect[i][1]);
        for(int j=2;j<=width;j++)
            printf(" %d",rect[i][j]);
        putchar(\'\n\');
    }
}

int main()
{
    scanf("%d%d",&high,&width);
    Init();
    SetNum();
    PutOut();
    return 0;
}