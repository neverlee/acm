#include <cstdio>
#include <cstring>
int main()
{
    short k,len;
    scanf("%d",&k);
    getchar();
    char str[1010];
    for(int i=0;i<k;i++)
    {
        gets(str);
        len=strlen(str);
        for(int j=len-1;j>=0;j--)
            putchar(str[j]);
        putchar(\'\n\');
    }
    return 0;
}