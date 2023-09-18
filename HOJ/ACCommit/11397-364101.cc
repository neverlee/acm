#include <cstdio>
char str[500010];
int base,total;
int main()
{
    while(scanf("%d %s",&base,str)!=EOF)
    {
        total=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]<=\'9\'){total+=(str[i]-\'0\');continue;}
            if(str[i]<=\'Z\'){total+=(str[i]-\'A\'+10);continue;}
            total+=(str[i]-\'a\'+36);
        }
        if(total%(base-1))printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}