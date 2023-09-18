#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int NODE=30010;
int chd[NODE][2],word[NODE],fail[NODE],sz;
char s[NODE];

void ins(char *s)
{
    int p=0;
    for(;*s;s++)
    {
        int id=*s-\'0\';
        if(!chd[p][id])
        {
            memset(chd[sz],0,sizeof(chd[sz]));
            word[sz]=0;
            chd[p][id]=sz++;
        }
        p=chd[p][id];
    }
    word[p]=1;
}
void ac()
{
    queue<int> q;
    if(chd[0][0]) q.push(chd[0][0]),fail[chd[0][0]]=0;
    if(chd[0][1]) q.push(chd[0][1]),fail[chd[0][1]]=0;
    for(;!q.empty();q.pop())
    {
        int p=q.front();
        for(int i=0;i<2;i++)
            if(chd[p][i])
            {
                q.push(chd[p][i]);
                fail[chd[p][i]]=chd[fail[p]][i];
                word[chd[p][i]]|=word[fail[chd[p][i]]];
            }else chd[p][i]=chd[fail[p]][i];
    }
}

int dfn[NODE],index;

bool dfs(int u)
{
    dfn[u]=1;
    for(int i=0;i<2;i++)
    {
        int v=chd[u][i];
        if(word[v]) continue;
        if(dfn[v]==1) return 1;
        if(dfn[v]==0&&dfs(v)) return 1;
    }
    dfn[u]=-1;
    return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(chd[0],0,sizeof(chd[0]));
        sz=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            ins(s);
        }
        ac();
        bool ok=0;
        memset(dfn,0,sizeof(dfn));
        index=1;
        for(int i=0;i<sz;i++)
            if(!dfn[i]&&dfs(i)) { ok=1;break; }
        puts(ok?"TAK":"NIE");
    }
    return 0;
}
