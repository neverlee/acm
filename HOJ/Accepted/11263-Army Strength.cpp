//11263-Army Strength.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
const int SIZE = 1000010;
int god[SIZE],mgo[SIZE];
void Init(){
	scanf("%ld%ld",god,mgo);
	for(int i=1;i<=god[0];++i)scanf("%ld",god+i);
	for(int i=1;i<=mgo[0];++i)scanf("%ld",mgo+i);
	sort(god+1, god+god[0]+1);
	sort(mgo+1, mgo+mgo[0]+1);
}
char Work(){
	int m=1,g=1,e=god[0]+mgo[0];
	while(--e){
		if(god[g]<mgo[m])++g;
		else ++m;
		if(g==god[0]+1)return 'm';
		if(m==mgo[0]+1)return 'g';
	}
	return 0;
}
int main(){
	int ncase;scanf("%ld",&ncase);
	while(ncase--){
		Init();
		char rs=Work();
		if(rs=='m')printf("MechaGodzilla\n");
		if(rs=='g')printf("Godzilla\n");
		if(rs==0)printf("uncertain\n");
	}
	return 0;
}