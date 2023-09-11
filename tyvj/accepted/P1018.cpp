#include <cstdio>
#include <cstring>
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int snb[100];
	memset(snb, 0, sizeof(snb));
	snb[0]=1;
	int wei=1, zero=0;
	for(int i=2; i<=n; ++i) {
		for(int j=0; j<wei; ++j)
			snb[j]*=i;
		for(int j=0; j<=wei; ++j) {
			snb[j+1]+=snb[j]/10;
			snb[j]%=10;
			if(j==wei&&snb[j]>0)++wei;
		}
	}
	while(snb[zero]==0) ++zero;
	int last=zero+k;
	last=last<wei?last:wei;
	for(int i=last-1; i>=zero; --i)
		putchar(snb[i]+'0');
}
