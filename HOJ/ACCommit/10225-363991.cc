#include <cstdio>
int main()
{
    char c;
    bool isLeft = 1;
    while((c=getchar())!=-1)
    {
        if(c==\'\"\')
        {
            if(isLeft)
            {printf("``");isLeft=0;}
            else
            {printf("\\'\\'");isLeft=1;}
        }
        else
            putchar(c);
    }
    return 0;
}