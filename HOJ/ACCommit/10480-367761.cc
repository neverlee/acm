#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

class StrNum
{
    public:
        char str[100];
        int len;
        void SetNum(){for(int i=0;i<20;i++)str[i]=0;len=0;};
        void Change(){for(int i=0;i<len;i++)str[i]-=\'0\';};
        void InWei();
        friend void Add(StrNum &n1,StrNum &n2);
}S1,S2;
int total;
void StrNum::InWei()
{
    for(int i=0;i<len;i++)
    {
        str[i+1]+=str[i]/10;
        total+=str[i]/10;
        str[i]%=10;
    }
}

void Add(StrNum &n1,StrNum &n2)
{
    int tn=n1.len>n2.len?n1.len:n2.len;
    for(int i=0;i<tn;i++)
        n1.str[i]+=n2.str[i];
    n1.len=tn;
    n1.InWei();
}

int main()
{
    while(S1.SetNum(),S2.SetNum(),scanf("%s %s",S1.str,S2.str)!=EOF)
    {
        getchar();total=0;
        if(S1.str[0]==\'0\')continue;
        S1.len=strlen(S1.str);
        S2.len=strlen(S2.str);
        reverse(S1.str,S1.str+S1.len);
        reverse(S2.str,S2.str+S2.len);
        S1.Change();S2.Change();
        Add(S1,S2);
        if(total==0)printf("No");
        else printf("%ld",total);
        printf(" carry operation");
        if(total>1)printf("s");
        printf(".\n");
    }
    return 0;
}
