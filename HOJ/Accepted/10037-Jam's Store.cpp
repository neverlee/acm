//10037-Jam's Store.cpp
#include<cstdio>
#include<cmath>
#include<algorighm>
using namespace std;
struct Point{
	short x,y;
	bool operator<(const Point&p)const{return y<p.y;}
}point[12];
int len;
double dps[2][12];
inline double Min(double a, double b){return a<b?a:b;}
inline double Distance(Point&a, Point&b, short sty){
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y+sty)*(b.y-a.y+sty));
}
void DoDp{
	--point[0].y;
	
}
int main(){
	while(scanf("%ld",&len),len){
		for(int i=0;i<len;++i)scanf("%d%d",&point[i].x,&point.y);
		sort(point, point+len);
	}
	return 0;
}