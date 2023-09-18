#include<cstdio>
#include<cstring>
int height,width,strNum,len;
bool isHave;
char rect[90][90]={0};
char str[30];
const char Dir[8][2]=
{-1,-1, -1,0, -1,1, 0,-1, 0,1, 1,-1, 1,0, 1,1};

void InitRect()
{
    scanf("%ld%ld",&width,&height);
    for(int i=1;i<=height;i++)
        for(int j=1;j<=width;j++)
        {getchar();rect[i][j]=getchar();}
}

void CheckString()
{
    int i,j,k,m;
    for(i=1;i<=height;i++)
        for(j=1;j<=width;j++)
          if(str[0]==rect[i][j])
            for(k=0;k<8;k++)
            {
                isHave=1;
                if(i+len*Dir[k][0]<1||i+len*Dir[k][0]>height)
                    continue;
                if(j+len*Dir[k][1]<1||j+len*Dir[k][1]>width)
                    continue;
                for(m=1;str[m];m++)
                    if(str[m]!=rect[i+m*Dir[k][0]][j+m*Dir[k][1]])
                    {isHave=0;break;}
                if(isHave)
                {
                    printf("(%ld,%ld)->(%ld,%ld)\n",
                        j,i,j+len*Dir[k][1],i+len*Dir[k][0]);
                    return;
                }
            }
}

void InitString()
{
    scanf("%ld",&strNum);getchar();
    while(strNum--)
    {
        gets(str);
        len=strlen(str)-1;
        CheckString();
    }
}

int main()
{
    InitRect();
    InitString();
    return 0;
}