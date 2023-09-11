#include <cstdio>
#include <cstdlib>

class Queen{
private:
	int size;
	int data[20];
	int reg[3][20];
	int reged, have, total;
public:
	void init() {
		scanf("%d", &size);
		reged=0;
	}
	bool canPut(int xpos, int ypos) {
		int i;
		for(i=0; i<xpos; ++i) {
			if (data[i]==ypos || abs(ypos-data[i])==xpos-i)
				return false;
		}
		return true;
	}
	void dg(int xpos) {
		int i;
		if (xpos>=size) {
			if (reged<3) {
				for(i=0; i<size; ++i)
					reg[reged][i]=data[i];
				++reged;
			}
			++have;
			return;
		}
		for (i=1; i<=size; ++i) {
			if (canPut(xpos, i)) {
				data[xpos]=i;
				dg(xpos+1);
			}
		}
	}
	void output() {
		int i,j;
		for (i=0; i<reged; ++i) {
			for (j=0; j<size-1; ++j)
				printf("%d ", reg[i][j]);
			printf("%d\n", reg[i][size-1]);
		}
		printf("%d", total);
	}
	void work() {
		int ret[20], i, end;
		end = size/2 + size%2;
		for (i=0; reged<3||i<end; ++i) {
			have=0;
			data[0]=i+1;
			dg(1);
			ret[i]=have;
		}
		total=0;
		for (i=0; i<end; ++i) total+=2*ret[i];
		if (size%2) total-=ret[end-1];
		output();
	}
};
int main() {
	Queen cq;
	cq.init();
	cq.work();
}