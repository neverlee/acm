//11098-二叉树遍历.cpp
#include<cstdio>
char syb[1010];
int left[1010],right[1010],point,head;

void Init(){
	scanf("%ld",&point);
	bool ptf[1010]={0};
	for(int i=1;i<=point;++i){
		getchar();
		scanf("%c %ld %ld",&syb[i],&left[i],&right[i]);
		left[i];right[i];
		ptf[left[i]]=ptf[right[i]]=1;
	}
	for(int i=1;i<=point;++i){
		if(!ptf[i]){
			head=i;
			break;
		}
	}
}

void First(int p){
	if(p)return;
	putchar(syb[p]);
	First(left[p]);
	First(right[p]);
}

int main(){
	int ncase;scanf("%ld",&ncase);
	for(int test=0;test<ncase;){
		printf("Case %ld:\n",++test);
		Init();
		First(head);
		putchar('\n');
	}
	return 0;
}