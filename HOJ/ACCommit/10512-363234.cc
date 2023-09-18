#include <cstdio>
short height, width;

char rect[202][201];
short result[201];
int main()
{
    scanf("%d%d",&height,&width);
    getchar();
    for(int i=0;i<height;i++)
        scanf("%s",rect[i]);
    for(int i=0;i<width;i++)
        rect[height][i]=\'#\';
    for(int i=0;i<201;i++)
        result[i]=0;
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            if(rect[j][i]==\'*\')
            {
                int k=j+1;
                while(rect[k][i]==\'*\')k++;
                result[k-j]++;
                j=k;
            }
        }
    }
    for(int i=1;i<201;i++)
        if(result[i])
            printf("%d %d\n",i,result[i]);
    return 0;
}