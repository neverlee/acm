//10432-半数集问题.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
__int64 queue[250000];
short recent[250000], num;
int front, back;
void Init(){
	queue[0]=num;
	recent[0]=num;
	front=0;back=1;
	__int64 k;
	short m;
	while(front<back){
		for(k=10;k<=queue[front];k*=10);
		m=recent[front]>>1;
		for(int i=1;i<=m;++i){
			queue[back]=queue[front]+k*i;
			recent[back]=i;
			++back;
		}
		++front;
	}
	sort(queue, queue+back);
	queue[back]=0;
	int total=0;
	for(int i=0;i<back;++i)
		if(queue[i]!=queue[i+1])++total;
	printf("%ld\n",total);
}
int main(){
    scanf("%d", &num);
    Init();
    return 0;
}
