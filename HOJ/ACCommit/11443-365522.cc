#include <cstdio>
int rect[3][3];
int zx,zy;
void Move()
{
    int step;char go[3];
    scanf("%ld",&step);getchar();
    for(int s=0;s<step;s++)
    {
        scanf("%s",go);
        switch(go[0])
        {
            case \'U\':
                if(zx>0)
                {
                    rect[zx][zy]=rect[zx-1][zy];
                    rect[zx-1][zy]=0;
                    zx--;
                }
                break;
            case \'D\':
                if(zx<2)
                {
                    rect[zx][zy]=rect[zx+1][zy];
                    rect[zx+1][zy]=0;
                    zx++;
                }
                break;
            case \'L\':
                if(zy>0)
                {
                    rect[zx][zy]=rect[zx][zy-1];
                    rect[zx][zy-1]=0;
                    zy--;
                }
                break;
            case \'R\':
                if(zy<2)
                {
                    rect[zx][zy]=rect[zx][zy+1];
                    rect[zx][zy+1]=0;
                    zy++;
                }
                break;
        }
    }
}

void PutOut()
{
    for(int i=0;i<3;i++)
        printf("%ld %ld %ld\n",rect[i][0],rect[i][1],rect[i][2]);
}

int main()
{
    int ncase;
    scanf("%ld",&ncase);
    for(int text=0;text<ncase;text++)
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                scanf("%Ld",&rect[i][j]);
                if(rect[i][j]==0){zx=i;zy=j;}
            }
        Move();
        PutOut();
        printf("\n");
    }
    return 0;
}