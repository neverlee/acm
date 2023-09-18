#include<cstdio>
#include<cstring>
char str[200100],re;
int bn1,bn2,en1,en2;

inline bool IsEle(char ch)
{return (ch>=\'0\'&&ch<=\'9\')||(ch>=\'A\'&&ch<=\'Z\');}

int main()
{
    while(gets(str))
    {
        if(str[0]==\'*\'&&str[2]==\'*\')return 0;
        en2=strlen(str);
        while(!IsEle(str[en2-1]))--en2;
        str[en2]=0;
        for(bn1=0;str[bn1]==\'0\';bn1++);
        for(en1=bn1;str[en1]!=\' \';en1++);
        str[en1]=0;
        for(bn2=en1+1;str[bn2]==\'0\';bn2++);
        //printf("%d %d %d %d\n",bn1,en1,bn2,en2);
        re=0;
        if(en1-bn1>en2-bn2)re=1;
        if(en1-bn1<en2-bn2)re=-1;
        if(en1-bn1==en2-bn2)
            for(;bn1<en1;++bn1,++bn2)
            {
                if(str[bn1]>str[bn2]){re=1;break;}
                if(str[bn1]<str[bn2]){re=-1;break;}
            }
        switch(re)
        {
            case 0:printf("=\n");break;
            case 1:printf(">\n");break;
            case -1:printf("<\n");
        }
    }
}