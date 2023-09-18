#include<cstdio>
#include<map>
#include<string>
using namespace std;
int total,need;
int main()
{
    map<string,int> record;
    char intemp[20];
    string strtemp;
    while(scanf("%ld %ld",&total,&need)!=EOF)
    {
        for(int i=0;i<total;i++)
        {
            scanf("%s",intemp);
            strtemp=intemp;
            if(record.find(strtemp)!=record.end())
                ++record[strtemp];
            else
                record.insert(make_pair(strtemp,1));
        }
        for(int i=0;i<need;i++)
        {
            scanf("%s",intemp);
            strtemp=intemp;
            if(record.find(strtemp)!=record.end())
                printf("%ld\n",record[strtemp]);
            else
                printf("0\n");
        }
        record.clear();
    }
    return 0;
}