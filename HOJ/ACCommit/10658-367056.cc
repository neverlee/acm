#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct BigLatter
{
    public:
        char pos;int num;
    bool operator<(const BigLatter &r) const 
    {
        if(r.num!=num)return r.num<num;
        else
            return pos<r.pos;
    }
}Latter;

Latter latter[26];
int main()
{
    int row;scanf("%ld",&row);getchar();
    char str[1000];
    for(int i=0;i<26;i++)
        {latter[i].pos=i+\'A\';latter[i].num=0;}
    while(gets(str))
    {
        ;
        for(int i=0;str[i];i++)
        {
            if(str[i]>=\'a\'&&str[i]<=\'z\')str[i]-=32;
            if(str[i]>=\'A\'&&str[i]<=\'Z\')
                latter[str[i]-\'A\'].num++;
        }
    }
    sort(latter,latter+26);
    for(int i=0;i<26&&latter[i].num;i++)
        printf("%c %ld\n",latter[i].pos,latter[i].num);
    return 0;
}
