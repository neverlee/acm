#include <cstdio>
#include <cstring>
char last[20]="ENDOFINPUT";
int main()
{
    char str[300];
    while(gets(str))
    {
        if(!strcmp(last,str))return 0;
        gets(str);
        for(int i=0;str[i];i++)
        {
            if(str[i]<=\'Z\'&&str[i]>=\'A\')
            {str[i]-=5;if(str[i]<\'A\')str[i]+=26;}
            if(str[i]<=\'z\'&&str[i]>=\'a\')
            {str[i]-=5;if(str[i]<\'a\')str[i]+=26;}
        }
        puts(str);
        gets(str);
    }
}