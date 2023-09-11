#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace::std;

typedef struct {
    int x,y,step,deep;
}Amaze;
Amaze queue[11000],amaze;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
char a[110][110],d[26],dir;
bool b[110][110];
int n,x1,x2,y1,y2,cnt;

bool position(int i)
{
    x1=amaze.x+dx[i];
    y1=amaze.y+dy[i];
    if (x1>=0&&x1<n&&y1>=0&&y1<n&&!b[x1][y1]&&a[x1][y1]!='*')
        return true;
    return false;
}

bool pos(char dir,int x2,int y2)
{
    if (dir=='N'&&(x2-1<0||a[x2-1][y2]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='S'&&(x2+1>=n||a[x2+1][y2]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='W'&&(y2-1<0||a[x2][y2-1]=='*'))
    {
        cnt++;
        return false;
    }
    if (dir=='E'&&(y2+1>=n||a[x2][y2+1]=='*'))
    {
        cnt++;
        return false;
    }
    return true;
}

int findpath(int xp,int yp)
{
    int i,lab=0,stop=1,deepth;
    memset(b, false, sizeof(b));
    amaze.x=xp;
    amaze.y=yp;
    amaze.step=0;
    amaze.deep=1;
    deepth=0;
    queue[0]=amaze;
    dir='N';
    b[xp][yp]=true;
    if ((xp==x2&&yp==y2)||(abs(xp-x2)==1&&abs(yp-y2)==0)||abs(yp-y2)==1&&abs(xp-x2)==0)
        return 0;
    while (lab!=stop) 
    {
        if (amaze.deep==deepth+1)
        {
            deepth=amaze.deep;
            cnt=0;
            while (!pos(dir,x2,y2)&&cnt<4)
                dir=d[dir-'A'];
            if (cnt>=4)
                return -1;
            if (dir=='N')
                x2--;
            if (dir=='E')
                y2++;
            if (dir=='S')
                x2++;
            if (dir=='W')
                y2--;
        }
        for (i=0; i<4; i++) 
        {
            if (position(i)) 
            {
                if ((x1==x2&&y1==y2)||(abs(x1-x2)==1&&abs(y1-y2)==0)||
                    (abs(y1-y2)==1&&abs(x1-x2)==0))
                    return queue[lab].step+1;
                queue[stop].x=x1;
                queue[stop].y=y1;
                queue[stop].step=queue[lab].step+1;
                queue[stop].deep=queue[lab].deep+1;
                stop++;
                b[x1][y1]=true;
            }
        }
        amaze=queue[++lab];
    }
    return -1;
}

int main()
{
    int i,j,xp,yp,result;
    d[4]='S';
    d[13]='E';
    d[18]='W';
    d[22]='N';
    while (cin >> n&&n) {
        for (i=0; i<n; i++)
            cin >> a[i];
        for (i=0; i<n; i++) 
            for (j=0; j<n; j++)
            {
                if (a[i][j]=='F')
                {
                    xp=i;
                    yp=j;
                }
                if (a[i][j]=='J')
                {
                    x2=i;
                    y2=j;
                }
            }
        result=findpath(xp,yp);
        if (result!=-1)
            cout << result << '\n';
        else 
            cout << "No solution.\n";
    }
    return 0;
}

