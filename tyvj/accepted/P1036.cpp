#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
	int num, count;
	bool operator<(const Node &n) {
		return num<n.num;
	}
};
const int SIZE = 30001;
const int UNLIMIT = 1600000000;
class HashNum{
	Node data[SIZE];
public:
	HashNum() {
		int i;
		for (i=0; i<SIZE; ++i) {
			data[i].num=UNLIMIT;
			data[i].count=0;
		}
	}
	void addNum(int num) {
		int k;
		k=num%SIZE;
		while(data[k].num!=UNLIMIT&&data[k].num!=num) {
			k=(k+1)%SIZE;
		}
		data[k].num=num;
		++data[k].count;
	}
	void output() {
		int i;
		sort(data, data+SIZE);
		for (i=0; i<SIZE; ++i)
		if (data[i].num!=UNLIMIT)
			printf("%d %d\n", data[i].num, data[i].count);
	}
};

int main() {
	int am, tp;
	HashNum hn;
	scanf("%d", &am);
	while(am--) {
		scanf("%d", &tp);
		hn.addNum(tp);
	}
	hn.output();
}
