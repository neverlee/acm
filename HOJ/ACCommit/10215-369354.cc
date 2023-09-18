#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

class Words
{
public:
    int source, target, len;
public:
    static int GetInt(char *str, int &len);
    void Set(char *str);
    bool operator<(const Words &w2)const;
    void PutOut();
};

int Words::GetInt(char *str, int &len)
{
    int k=0,temp=1;
    for(int i=len-1;i>=0;i--)
    {
        k+=((str[i]-\'a\'+1)*temp);
        temp*=27;
    }
    return k;
}

void Words::Set(char *str)
{
    len=strlen(str);
    source = GetInt(str, len);
    sort(str,str+len);
    target = GetInt(str, len);
}

bool Words::operator<(const Words &w2)const
{
    if(target<w2.target)
        return true;
    if(target==w2.target&&source<w2.source)
        return true;
    return false;
}

void Words::PutOut()
{
    char str[10];
    str[len]=0;
    int k=source;
    for(int i=len-1;i>=0;i--)
    {
        str[i]=k%27+\'a\'-1;
        k/=27;
    }
    //printf("%s %ld %ld\n",str,source,target);
    puts(str);
}
Words sword[110];
int main()
{
    int num=0;
    char str[10];
    while(gets(str))
    {
        if(str[0]==\'X\')break;
        sword[num++].Set(str);
    }
    sort(sword,sword+num);
    int k,len,temp;
    while(gets(str))
    {
        if(str[0]==\'X\')break;
        len=strlen(str);
        sort(str,str+len);
        temp=sword[0].GetInt(str,len);
        for(k=0;k<num;k++)if(temp<=sword[k].target)break;
        if(k==num||temp<sword[k].target)
            printf("NOT A VALID WORD\n");
        else
            for(;k<num;k++)
                if(temp==sword[k].target)sword[k].PutOut();
        printf("******\n");
    }
}