#include <cstdio>
#include <algorithm>
using namespace std;

int kind, least;
struct Coin{
	int v,c;
}coins[22];

bool cmp(const Coin &a, const Coin &b) {
	return a.v<b.v;
}

void init() {
	scanf("%d%d", &kind, &least);
	for(int i=0; i<kind; ++i)
		scanf("%d%d", &coins[i].v, &coins[i].c);
	sort(coins, coins+kind, cmp);
}

void getAnswer() {
	int sum=0;
	for(--kind; kind>=0&&coins[kind].v>=least; )
		sum += coins[kind--].c;
	while(1) {
		int ned[22], dn=least;
		for(int i=kind; i>=0; --i) {
			int k = dn/coins[i].v;
			if(k>coins[i].c) k=coins[i].c;
			dn-=coins[i].v*k;
			coins[i].c-=k;
			ned[i]=k;
		}
		for(int i=0; i<=kind&&dn>0; ++i) {
			int k=dn/coins[i].v;
			if(dn%coins[i].v) ++k;
			if(k>coins[i].c) k=coins[i].c;
			dn-=coins[i].v*k;
			coins[i].c-=k;
			ned[i]+=k;
		}
		if(dn<=0) ++sum;
		else break;
		int mi=1E8;
		for(int i=0; i<=kind; ++i)
		if(ned[i]) {
			int k=coins[i].c/ned[i];
			mi=mi<k?mi:k;
		}
		for(int i=0; i<=kind; ++i)
			coins[i].c-=mi*ned[i];
		sum+=mi;
	}
	printf("%d", sum);
}

int main() {
	init();
	getAnswer();
}
