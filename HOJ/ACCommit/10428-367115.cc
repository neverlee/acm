#include <cstdio>
#include <cstring>
char str[300],stack[300];
int main()
{
    int s;
    while(gets(str))
    {
        s=0;
        for(int i=0;i<str[i];i++)
        {
            if(str[i]==\'#\')
            {if(s>0)s--;continue;}
            if(str[i]==\'@\')
            {s=0;continue;}
            stack[s++]=str[i];
        }
        stack[s]=0;
        if(stack[0])puts(stack);
    }
    return 0;
}