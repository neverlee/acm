#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int id, dist;
	node *next;
	node (int i=0, int d=0, node *n=NULL) {
		id=i;
		dist=d;
		next=n;
	}
};

class City{
private:
	vector<node> map;
	int city, road, start, end;
	void insert (int a, int b, int d){
		node *p=map[a].next;
		map[a].next = new node(b,d,p);
	}
public:
	City() {
		scanf ("%d%d%d%d", &city, &road, &start, &end);
		map.reserve(city+1);
		map.resize(city+1);
		int a, b, d;
		while (road--) {
			scanf ("%d%d%d", &a, &b, &d);
			insert (a,b,d);
			insert (b,a,d);
		}
	}
	void visit() {
		const int UNLIMIT = 1E8;
		for (int i=0; i<=city; ++i) {
			map[i].dist = UNLIMIT;
		}
		map[start].dist = 0;
		map[start].id = 1;
		queue<int> qi;
		qi.push(start);
		while (!qi.empty()) {
			if (--map[qi.front()].id==0) {
				node *p=map[qi.front()].next;
				for (; p; p=p->next) {
					int newDist;
					newDist = map[qi.front()].dist+p->dist;
					if (newDist<map[p->id].dist){
						map[p->id].dist = newDist;
						++map[p->id].id;
						qi.push(p->id);
					}
				}
			}
			qi.pop();
		}
		printf ("%d", map[end].dist);
	}
};

int main() {
	City ci;
	ci.visit();
}
