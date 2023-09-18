//10735-Rock-Paper-Scissors Tournament.cpp
#include<cstdio>
#include<cstring>
int n,k,rs[2][100], a,b, len, r;
char s1[10],s2[10];
int Check(){
	if(s1[0]==s2[0])return 2;
	if(    (s1[0]=='r'&&s2[0]=='s')
		|| (s1[0]=='s'&&s2[0]=='p')
		|| (s1[0]=='p'&&s2[0]=='r') )return 0;
	return 1;
}
int main(){
	scanf("%ld",&n);
	while(n){
		scanf("%ld",&k);
		memset(rs,0,sizeof(rs));
		if(n!=1){
			len=k*n*(n-1)/2;
			while(len--){
				scanf("%ld %s %ld %s",&a, s1, &b, s2);
				--a;--b;
				r=Check();
				if(r==2)continue;
				rs[0][a]+=(1-r);
				rs[1][a]+=r;
				rs[0][b]+=r;
				rs[1][b]+=(1-r);
			}
			for(int i=0;i<n;++i)
			if(rs[0][i]+rs[1][i]>0)
			printf("%.3lf\n", ((double)rs[0][i])/(rs[0][i]+rs[1][i]));
			else puts("-");
		}else puts("-");
		scanf("%ld",&n);
		if(n)puts("");
	}
}
