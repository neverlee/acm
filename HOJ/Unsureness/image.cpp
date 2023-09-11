// 10.cpp : 定义控制台应用程序的入口点。
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
	short x,y;
	Point(){};
	Point(short ax, short ay){x=ax;y=ay;}
};
int mins(int a,int b){return a>b?b:a;}
class Image{
protected:
	short height, width;
	char byte[256][256];
	vector<Point> dir;
public:
	Image();
	void Run();
	void DoC(short hi, short wd);
	void DoI(char *command);
	void DoL(char *command);
	void DoV(char *command);
	void DoH(char *command);
	void DoK(char *command);
	void DoF(char *command);
	void DoS(char *command);
};
Image::Image(){
	height = width = 0;
	dir.push_back(Point(-1,0));
	dir.push_back(Point(0,-1));
	dir.push_back(Point(1,0));
	dir.push_back(Point(0,1));
	dir.push_back(Point(-1,-1));
	dir.push_back(Point(-1,1));
	dir.push_back(Point(1,-1));
	dir.push_back(Point(1,1));
}
void Image::DoC(short hi, short wd){
	for(short i=0;i<hi;++i){
		for(short j=0;j<wd;++j){
			byte[i][j]='O';
		}
	}
}

void Image::Run(){
	char command[200];
	while(gets(command)){
		switch(command[0]){
			case 'I':DoI(command+2);break;
			case 'C':DoC(height, width);break;
			case 'L':DoL(command+2);break;
			case 'V':DoV(command+2);break;
			case 'H':DoH(command+2);break;
			case 'K':DoK(command+2);break;
			case 'F':DoF(command+2);break;
			case 'S':DoS(command+2);break;
			case 'X':return;
			default:;
		}
	}
}
void Image::DoI(char *cmd){
	short hi, wd;
	sscanf(cmd, "%d %d", &wd, &hi);
	height=hi; width=wd;
	DoC(hi,wd);
}
void Image::DoL(char *cmd){
	short hi, wd; char color;
	sscanf(cmd, "%d %d %c", &wd, &hi, &color);
	if(wd<=width&&hi<=height)
		byte[hi-1][wd-1]=color;
}
void Image::DoV(char *cmd){
	short wdp, hi1, hi2; char color;
	sscanf(cmd, "%d %d %d %c", &wdp, &hi1, &hi2, &color);
	short tmp;
	if(hi2<hi1){tmp=hi1;hi1=hi2;hi2=tmp;}
	hi2=mins(hi2,height);
	for(short i=hi1-1;i<hi2;++i){
		byte[i][wdp-1]=color;
	}
}
void Image::DoH(char *cmd){
	short wd1, wd2, hip; char color;
	sscanf(cmd, "%d %d %d %c", &wd1, &wd2, &hip, &color);
	short tmp;
	if(wd1>wd2){tmp=wd1;wd1=wd2;wd2=tmp;}
	wd2=mins(wd2,width);
	for(short i=wd1-1;i<wd2;++i){
		byte[hip-1][i]=color;
	}
}
void Image::DoK(char *cmd){
	short x1, y1, x2, y2, tmp; char color;
	sscanf(cmd, "%d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
	if(x2<x1){tmp=x1;x1=x2;x2=tmp;}
	if(y2<y1){tmp=y1;y1=y2;y2=tmp;}
	x2=mins(x2,width);
	y2=mins(y2,height);
	for(short i=x1-1;i<x2;++i){
		for(short j=y1-1;j<y2;++j){
			byte[j][i]=color;
		}
	}
}
void Image::DoF(char *cmd){
	short x, y;char newc,oldc;
	sscanf(cmd, "%d %d %c", &y, &x, &newc);
	if(newc==byte[x-1][y-1])return;
	queue<Point, list<Point> > record;
	oldc=byte[x-1][y-1];
	byte[x-1][y-1]=newc;
	record.push(Point(x-1,y-1));
	short ax,dx,ay,dy;
	while(!record.empty()){
		for(int i=0;i<dir.size();++i){
			ax=record.front().x;
			ay=record.front().y;
			dx=ax+dir[i].x;dy=ay+dir[i].y;
			if(dy<0||dy>width)continue;
			if(dx<0||dx>height)continue;
			if(byte[dx][dy]==oldc){
				byte[dx][dy]=newc;
				record.push(Point(dx,dy));
			}
		}
		record.pop();
	}
}
void Image::DoS(char *s){
	puts(s);
	for(short i=0;i<height;++i){
		for(short j=0;j<width;++j){
			putchar(byte[i][j]);
		}
		putchar('\n');
	}
}

int main(){
	Image img;
	img.Run();
	return 0;
}
