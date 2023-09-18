#include <cstdio>
#include <cstring>
int main()
{
    char str[1000];int len;double kn;
    while(gets(str))
    {
        len=strlen(str);kn=0.0;
        bool obey=1;
        for(int i=0;i<len;i+=2)
        {
            switch(str[i])
            {
                case \'A\':
                    kn+=4;break;
                case \'B\':
                    kn+=3;break;
                case \'C\':
                    kn+=2;break;
                case \'D\':
                    kn+=1;break;
                case \'F\':break;
                default:
                    obey=0;
            }
            if(!obey)break;
        }
        if(obey)printf("%.2lf\n",kn/((double)(len/2+1)));
        else printf("Unknown letter grade in input\n");
    }
}