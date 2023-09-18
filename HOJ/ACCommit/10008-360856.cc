#include <cstdio>
char rex[800][800];
short nx,nx3;

void DeepGo(short nx,short xs,short xe,short ys,short ye)
{
    if(nx==1){rex[xs][ys]=\'X\';return;}
    short dv3=(xe-xs+1)/3;
    DeepGo(nx-1,xs,xs+dv3-1, ys,ys+dv3-1);
    DeepGo(nx-1,xe-dv3+1,xe, ys,ys+dv3-1);
    DeepGo(nx-1,xs+dv3,xe-dv3, ys+dv3,ye-dv3);
    DeepGo(nx-1,xs,xs+dv3-1, ye-dv3+1,ye);
    DeepGo(nx-1,xe-dv3+1,xe, ye-dv3+1,ye);
}
void OutPut()
{
    for(int i=1;i<=nx3;i++)
    {
        for(int j=nx3;j>0;j--)
            if(rex[i][j]==\'X\')
            {rex[i][j+1]=\'\0\';break;}
        puts(rex[i]+1);
    }
    printf("-\n");
}

int main()
{

    while(scanf("%d",&nx))
    {
        if(nx==-1)return 0;
        nx3=1;
        for(int i=1;i<nx;i++)
            nx3*=3;
        for(int i=1;i<=nx3;i++)
            for(int j=1;j<=nx3;j++)
                rex[i][j]=\' \';
        DeepGo(nx,1,nx3,1,nx3);
        OutPut();
    }
    return 0;
}