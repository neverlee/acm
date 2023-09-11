// 10147-Shortest path in the a Maze.cpp : 定义控制台应用程序的入口点。
//
//11837

#include"stdafx.h"

#include<cstdio>
#include<queue>
#include<list>
#include<cstdlib>
using namespace std;

class Point{
public:
	int x,y;
	void Set(int ax,int ay){x=ax;y=ay;}
	Point(){}
	Point(int ax,int ay){Set(ax,ay);}
	void Get(int &ax,int &ay){ax=x;ay=y;}
};
class Maze{
private:
	const short SPACE, STAR;
	short map[100][100];
	short hi,wd;
	vector<Point> dir;
	Point start,end;
public:
	Maze():SPACE(32700),STAR(-1){
		scanf("%d %d", &wd,&hi);
		short tmp;
		for(int i=1;i<=hi;++i){
			for(int j=1;j<=wd;++j){
				scanf("%d",&tmp);
				if(tmp)map[i][j]=SPACE;
				else map[i][j]=STAR;
			}
		}
		short h,w;
		scanf("%d%d",&w,&h);
		start.Set(w,h);
		scanf("%d%d",&w,&h);
		end.Set(w.h);
		
	}
	void InitDir(){
		dir.push_back(Point(-1,0));
		dir.push_back(Point(0,-1));
		dir.push_back(Point(0,1));
		dir.push_back(Point(1,0));
	}
	int GoThrough(){
		queue<Point, list<Point> > record;
		record.push(start);
		rote[start.x][start.y]=1;
		int x,y,dx,dy;
		while(!record.empty()){
			if(rote[end.x][end.y])break;
			record.front().Get(x,y);
			for(int i=0;i<dir.size();++i){
				dx=x+dir[i].x;dy=y+dir[i].y;
				if(dx<=0||dx>hi)continue;
				if(dy<=0||dy>wd)continue;
				if(map[dx][dy]=='O'	&&
					(rote[dx][dy]==0||rote[dx][dy]>rote[x][y]+1)){
					rote[dx][dy]=rote[x][y]+1;
					record.push(Point(dx,dy));
				}
			}
			record.pop();
		}
		return rote[end.x][end.y];
	}
};
int main(){
	int ncase;
	scanf("%ld",&ncase);
	while(ncase--){
		Maze aex;
		aex.InitDir();
		printf("%ld", aex.GoThrough());
	}
	return 0;
}