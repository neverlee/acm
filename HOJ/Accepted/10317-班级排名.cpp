//10317-班级排名.cpp
#include<cstdio>
#include<String>
#include<map>
using namespace std;
int num,test,times,tn;
char name[40];

map<string,int> grade;

void Init()
{
    scanf("%ld",&num);getchar();
    for(int i=0;i<num;i++)
    {
        gets(name);
        grade.insert(make_pair(string(name),0));
    }
}

void Answer()
{
    scanf("%ld",&test);
    map<string,int>::iterator iter;
    while(test--)
    {
        times=1;
        for(int i=0;i<num;i++)
        {
            scanf("%ld %s",&tn,name);
            grade[string(name)]+=tn;
        }
        tn=grade[string("JLY")];
        for(iter=grade.begin();iter!=grade.end();iter++)
            if(iter->second>tn)++times;
        printf("%ld\n",times);
    }
}

int main()
{
    Init();
    Answer();
    return 0;
}