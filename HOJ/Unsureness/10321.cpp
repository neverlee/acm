5
.*.*.
.*5..
.J.*.
..*..
..*.F


// 10321.cpp : 定义控制台应用程序的入口点。
//
//freopen("E:\\ACMIn.txt", "r", stdin);
//freopen("E:\\ACMOut.txt", "w", stdout);

#include"stdafx.h"

#include<cstdio>
#include<queue>
#include<list>
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
	const short STAR;
	const short SPACE;
	short map[110][110], len;
	vector<Point> dir;
	Point Feli, Dog;
	short recent;
public:
	Maze():STAR(-1),SPACE(32759){
		scanf("%d", &len);
		char tmp;
		recent=0;
		for(int i=1;i<=len;++i){
			getchar();
			for(int j=1;j<=len;++j){
				tmp=getchar();
				switch(tmp){
				case '.':map[i][j]=SPACE;break;
				case '*':map[i][j]=STAR;break;
				case 'F':Feli.Set(i,j);map[i][j]=SPACE;break;
				case 'J':Dog.Set(i,j);map[i][j]=SPACE;break;
				}
			}
		}
		for(int i=0;i<=len+1;++i){
			map[0][i]=map[i][0]=map[len+1][i]=map[i][len+1]=STAR;
		}
		InitDir();
	}
	void InitDir(){
		dir.push_back(Point(-1,0));
		dir.push_back(Point(0,1));
		dir.push_back(Point(1,0));
		dir.push_back(Point(0,-1));
	}
	void GoNext(){
		short x,y,k;
		for(int i=0;i<dir.size();++i){
			k=(recent+i)%dir.size();
			x=Dog.x+dir[k].x;
			y=Dog.y+dir[k].y;
			if(map[x][y]!=STAR){
				Dog.Set(x,y);
				recent = k;
				return;
			}
		}
	}
	bool Catch(Point &p){
		if(Dog.x==p.x&&Dog.y==p.y)return true;
		short x,y;
		for(int i=0;i<dir.size();++i){
			x=Dog.x+dir[i].x;y=Dog.y+dir[i].y;
			if(x==p.x&&y==p.y)return true;
		}
		return false;
	}
	int GoThrough(){
		queue<Point, list<Point> > record;
		record.push(Feli);
		short foot=1;
		map[Feli.x][Feli.y]=0;
		int x,y,dx,dy;
		while(!record.empty()){
			record.front().Get(x,y);
			if(foot==map[x][y]){
				GoNext();
				++foot;
			}
			if(Catch(record.front())){
				printf("%d",map[x][y]);
				return 0;
			}
			for(int i=0;i<dir.size();++i){
				dx=x+dir[i].x;
				dy=y+dir[i].y;
				if(map[dx][dy]>map[x][y]+1){
					map[dx][dy]=map[x][y]+1;
					record.push(Point(dx,dy));
				}
			}
			record.pop();
		}
		return 1;
	}
};
int main(){
	Maze amz;
	if(amz.GoThrough())printf("No solution.");
	return 0;
}







