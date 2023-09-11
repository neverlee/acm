#include <cstdio>
int bag, cnt, tmp;
bool f[45010];
int main() {
	scanf("%d%d", &bag, &cnt);
	f[0]=1;
	while(cnt--) {
		scanf("%d", &tmp);
		for(int i=bag-tmp; i>=0; --i)
			if(f[i]) f[i+tmp]=1;
	}
	for(tmp=bag; f[tmp]==0; --tmp);
	printf("%d", tmp);
}

