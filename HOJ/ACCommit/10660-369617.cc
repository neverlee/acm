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
    scanf("%ld%ld",&height,&width);
    for(int i=0;i<height;i++)
        scanf("%s",rect[i]);
}

void CheckString()
{
    int i,j,k,m,temp;
    for(i=0;i<height;i++)for(j=0;j<width;j++){
        for(k=0;k<8;k++){
            if(i+len*Dir[k][0]<-1||i+len*Dir[k][0]>height)continue;
            if(j+len*Dir[k][1]<-1||j+len*Dir[k][1]>width)continue;
            for(m=0;m<len;m++){
                temp=rect[i+m*Dir[k][0]][j+m*Dir[k][1]];
                if(!(str[m]==temp||(str[m]+32==temp)||(str[m]-32==temp)))
                    break;
            }
            if(m>=len)
            {
                printf("%ld %ld\n",i+1,j+1);
                return;
            }
        }
    }
}

void InitString()
{
    scanf("%ld",&strNum);
    while(strNum--)
    {
        scanf("%s",str);
        len=strlen(str);
        CheckString();
    }
}

int main()
{
    InitRect();
    InitString();
    return 0;
}