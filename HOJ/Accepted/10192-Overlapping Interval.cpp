//10192-Overlapping Interval.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
struct Itv{
	int s,e;
	void Normal(){if(e<s){int t=s;s=e;e=t;}}
	bool operator<(const Itv &ni)const{
		return s<ni.s||(s==ni.s&&e<ni.e);
	}
}itv[10010];
int size;
int Get(){
	int max=0,tmp,i,j;
	for(i=0,j=1;i<size-1&&j<size;){
		if(i==j)++j;
		if(itv[i].e<=itv[j].e){
			tmp=itv[i].e-itv[j].s+1;
			++i;
		}else{
			tmp=itv[j].e-itv[j].s+1;
			++j;
		}
        max=max>tmp?max:tmp;
	}
	return max;
}
int main(){
	int ncase;scanf("%ld",&ncase);
	while(ncase--){
		for(size=0;;++size){
			scanf("%ld%ld", &itv[size].s, &itv[size].e);
			if(!(itv[size].s||itv[size].e))break;
			itv[size].Normal();
		}
		sort(itv, itv+size);
		printf("%ld\n",Get());
	}
	return 0;
}

