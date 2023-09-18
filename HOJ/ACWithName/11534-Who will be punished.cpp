// 11534-Who will be punished.cpp : 定义控制台应用程序的入口点。
//
//freopen("E:\\ACMIn.txt", "r", stdin);
//freopen("E:\\ACMOut.txt", "w", stdout);

#include"stdafx.h"

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

class Point{
public:
	Point(){}
	char *pt;
	void Set(char *p){
		pt=p;
	}
	static int Compare(Point &p1, Point &p2){
		return strcmp(p1.pt, p2.pt);
	}
	bool operator<(const Point &p)const{
		return strcmp(pt, p.pt)<0;
	}
};
const int SIZE = 500000;
char words[SIZE][31];
char ren[31];
Point pos[SIZE];
bool have[SIZE];
int num;

int BinarySearch(Point &val){
	int low=0, high=num-1, mid, cmp;
	if(0==Point::Compare(pos[low], val))return low;
	while(low<=high){
		mid=low+((high-low)/2);
		cmp = Point::Compare(pos[mid], val);
		if(cmp==0)return mid;
		if(cmp>0)high=mid-1;
		else low=mid+1;
	}
	return -1;
}

int main(){
	Point aren;aren.Set(ren);int test=0;
	while(EOF!=scanf("%ld",&num)){
		for(int i=0;i<num;++i){
			scanf("%s",words[i]);
			pos[i].Set(words[i]);
			have[i]=true;
		}
		sort(pos, pos+num);
		for(int i=0;i<num-1;++i){
			scanf("%s", ren);
			int k=BinarySearch(aren);
			have[k]=0;
		}
		printf("Scenario #%ld\n", ++test);
		for(int i=0;i<num;++i){
			if(have[i]){
				puts(pos[i].pt);
				break;
			}
		}
	}
	return 0;
}










