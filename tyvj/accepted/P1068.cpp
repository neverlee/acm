#include <cstdio>
#include <cstring>

const int SIZE = 200010;
char str1[SIZE]; int len1;
char str2[SIZE]; int len2;
int next[SIZE];

void get_next() {
	int i, j;
	i = 1; j = 0; next[1]=0;
	while( i<=len2 ) {
		if( j==0 || str2[i]==str2[j] ) {
			++i; ++j;
			if( str2[i]!=str2[j] )
				next[i] = j;
			else next[i] = next[j];
		}else j=next[j];
	}
}
int have[SIZE];
void index_kmp() {
	int i, j, k;
	i = 1; j = 1;
	while( i<=len1 ) {
		if( j==0 || str1[i]==str2[j] ) {
			++have[j];
			++i; ++j;
		}else j=next[j];
	}
}
int kmp[SIZE];
void other_kmp() {
	int i, j;
	i = 2; j = 1;
	--len2;
	while( i<=len2 ) {
		if( j==0 || str2[i]==str2[j] ) {
			kmp[i] = j;
			++i; ++j;
		}else j=next[j];
	}
}

void deal_last() {
	int i;
	for( i=len2; i>0; --i )
		have[kmp[i]] += have[i];
}
int nask;
int main() {
	scanf( "%d%d%d%*c", &len1, &len2, &nask );
	gets( str1+1 );
	gets( str2+1 );
	++len2;
	str2[len2]=-1;
	get_next();
	index_kmp();
	other_kmp();
	deal_last();
	int ask;
	while( nask-- ) {
		scanf( "%d", &ask );
		printf( "%d\n", have[ask]-have[ask+1] );
	}
	return 0;
}