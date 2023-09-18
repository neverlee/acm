#include<cstdio>
#include<queue>
#include<list>
#include<cstdlib>
#include<memory.h>
using namespace std;

class Point{
public:
    int x,y;
    void Set(int ax,int ay){x=ax;y=ay;}
    Point(){}
    Point(int ax,int ay){Set(ax,ay);}
    void Get(int &ax,int &ay){ax=x;ay=y;}
};
class Maze{
private:
    char map[100][100];
    char hi,wd;
    vector<Point> dir;
    Point start,end;
public:
    Maze(){
        memset(map, 0, sizeof(map));
        for(hi=1;EOF!=scanf("%s",map[hi]+1);++hi);
        --hi;
        wd=strlen(map[1]+1);
        start.Set(1,1);
        end.Set(hi,wd);
    }
    void InitDir(){
        dir.push_back(Point(-1,-1));
        dir.push_back(Point(-1,0));
        dir.push_back(Point(-1,1));
        dir.push_back(Point(0,-1));
        dir.push_back(Point(0,1));
        dir.push_back(Point(1,-1));
        dir.push_back(Point(1,0));
        dir.push_back(Point(1,1));
    }
    int GoThrough(){
        short rote[100][100]={0};
        queue<Point, list<Point> > record;
        record.push(start);
        rote[start.x][start.y]=1;
        int x,y,dx,dy;
        while(!record.empty()){
            if(rote[end.x][end.y])break;
            record.front().Get(x,y);
            for(int i=0;i<dir.size();++i){
                dx=x+dir[i].x;dy=y+dir[i].y;
                if(dx<=0||dx>hi)continue;
                if(dy<=0||dy>wd)continue;
                if(map[dx][dy]==\'O\'    &&
                    (rote[dx][dy]==0||rote[dx][dy]>rote[x][y]+1)){
                    rote[dx][dy]=rote[x][y]+1;
                    record.push(Point(dx,dy));
                }
            }
            record.pop();
        }
        return rote[end.x][end.y];
    }
};
int main(){
    Maze aex;
    aex.InitDir();
    printf("%ld", aex.GoThrough());
    return 0;
}