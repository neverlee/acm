#include <cstdio>
char rect[110][110];
char result[110][110];
int ncase,height,width;
int main()
{
    scanf("%d",&ncase);
    for(int text=0;text<ncase;text++)
    {
        scanf("%d%d",&width,&height);getchar();
        for(int i=1;i<=height;i++)
            gets(rect[i]+1);
        for(int i=0;i<=height+1;i++)
        {
            for(int j=0;j<=width+1;j++)
                result[i][j]=\'.\';
            result[i][width+2]=0;
        }
        for(int i=1;i<=height;i++)
            for(int j=1;j<=width;j++)
                if(rect[i][j]==\'*\')
                {
                    result[i][j]=\'*\';
                    result[i-1][j]=\'*\';
                    result[i+1][j]=\'*\';
                    result[i][j-1]=\'*\';
                    result[i][j+1]=\'*\';
                }
        for(int i=0;i<=height+1;i++)
            puts(result[i]);
        if(text!=ncase-1)printf("---\n");
    }
    return 0;
}