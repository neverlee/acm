#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct Word{
	char str[20];
	char ptn[20];
	int len;
	void init() {
		int i, j, k;
		memset( ptn, 0, sizeof(ptn) );
		len = strlen( str );
		for( i=0, k=1; str[i]; ++i )
		if( ptn[i]==0 ) {
			for( j=i; j<len; ++j )
				if( str[j]==str[i] )
					ptn[j] = k;
			++k;
		}
		ptn[len]=0;
	}
}word[1000];
struct PWord{
	Word *p;
	Word *operator->() { return p; }
	friend bool operator<( const PWord &pa, const PWord &pb ) {
		return strcmp( pa.p->ptn, pb.p->ptn ) < 0;
	}
}pwd[1000];
int word_amount;
void init_word() {
	int i;
	scanf( "%d", &word_amount );
	for( i=0; i<word_amount; ++i ) {
		scanf( "%s", word[i].str );
		word[i].init();
		pwd[i].p = word+i;
	}
	sort( pwd, pwd+word_amount );
}

char str[100];
int code_amount;
Word code[40];
pair<PWord*, PWord*> inv[40];
void init_code() {
	char divs[100];
	strcpy( divs, str );
	char *p=divs;
	int i;
	p = strtok( divs, " " );
	PWord pw;
	for( i=0; p; p = strtok( NULL, " " ), ++i ) {
		strcpy( code[i].str, p );
		code[i].init();
		pw.p = code+i;
		inv[i] = equal_range( pwd, pwd+word_amount, pw );
	}
	code_amount = i;
}
typedef vector<char> Vcc;
bool finish;
Vcc last;
void dfs( Vcc &ref, Vcc &use, int lv ) {
	int i;
	if( lv>=code_amount ) {
		last=ref;
		finish=1;
		return;
	}
	PWord *pp;
	for( pp=inv[lv].first; pp!=inv[lv].second; ++pp ) {
		char src, tag;
		bool flag=1;
		Vcc rn(ref), un(use);
		for( i=0; i<code[lv].len; ++i ) {
			src = code[lv].str[i]-'a';
			tag = (*pp)->str[i]-'a';
			if( (rn[src]==-1&&un[tag]==0) || rn[src]==tag ) {
				rn[src]=tag;
				un[tag]=1;
			}else {
				flag=0;
				break;
			}
		}
		if( flag )
			dfs( rn, un, lv+1 );
	}
}

int main() {
	init_word();
	getchar();
	while( gets( str ) ) {
		init_code();
		Vcc ref(26), use(26);
		fill( ref.begin(), ref.end(), -1 );
		fill( use.begin(), use.end(), 0 );
		
		int i;
		finish=0;
		dfs( ref, use, 0 );
		for( i=0; i<last.size(); ++i ) {
			if( finish ) last[i]+='a';
			else last[i] = '*';
		}
		
		for( i=0; str[i]; ++i ) {
			if( str[i]>='a' )
				putchar( last[str[i]-'a'] );
			else putchar(str[i]);
		}
		putchar('\n');
	}
}

