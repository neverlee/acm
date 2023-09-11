//10748-Judge The Problem Yourself.cpp
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

const char NO[] = "No Solution!";
char sexp[100], num[100], isno[100], exp[100];
int ret;

int getint( char *&p ) {
	int x=0;
	for( ;isdigit(*p) ; ++p )
		x = x*10+*p-'0';
	return x;
}

const double eps = 1E-7;
class Exp {
private:
	char exp[100];
	char *p;
	bool ineps( double x ) {
		if( x<eps && x>-eps ) return 1;
		return 0;
	}
	double A() {
		double ret;
		ret = M();
		while( *p=='+' || *p=='-' ) {
			++p;
			if( *(p-1)=='+' ) ret += M();
			else ret -= M();
		}
		if( *p!=0 && *p!=')' ) {
			error=1;
		}
		return ret;
	}
	double M() {
		double ret;
		ret = E();
		while( *p=='*' || *p=='/' ) {
			++p;
			if( *(p-1)=='*' ) ret *= E();
			else {
				double n = E();
				if( ineps(n) ) error=1;
				else ret /= n;
			}
		}
		if( *p!=0 && *p!=')' && *p!='+' && *p!='-' ) {
			error=1;
		}	
		return ret;
	}
	double E() {
		double n=0;
		if( *p=='(' ) {
			++p;
			n = A();
			if( *p!=')' ) error=1;
			++p;
		}else if( isdigit( *p ) ) {
			n = getint(p);
		}else {
			error=1;
		}
		return n;
	}
public:
	bool error;
	bool right;
	double ret;
	Exp( char *s ) {
		strcpy( exp, s );
	}
	void work() {
		error=0;
		right=0;
		p = exp;
		ret = A();
		if( *p!=0 ) error=1;
		if( ineps( ret-24 ) ) right=1;
	}
};

bool check_num() {
	int src[4], tag[10], l;
	char *p;
	p = num;
	for( int i=0; i<4; ++i ) {
		while( !isdigit( *p ) ) ++p;
		src[i] = getint(p);
	}
	sort( src, src+4 );
	p = exp;
	for( l = 0; l<5; ++l ) {
		while( !isdigit( *p ) && *p ) ++p;
		if( *p==0 ) break;
		tag[l] = getint(p);
	}
	if( l!=4 ) return 0;
	sort( tag, tag+4 );
	for( int i=0; i<4; ++i )
		if( src[i]!=tag[i] ) return 0;
	return 1;
}
int main() {
	for( int T=1; gets( sexp ); ++T ) {
		gets( num );
		gets( isno );
		memset( exp, 0, sizeof(exp) );
		for( int i=0, j=0; sexp[i]; ++i )
			if( sexp[i]!=' ' ) exp[j++] = sexp[i];
		ret = 0;
		if( strcmp( isno, NO ) == 0 ) {
			if( strcmp( exp, "NoSolution!" ) == 0 ) ret |= 1;
			if( strcmp( sexp, NO ) == 0 ) ret |= 2;
		}else {
			if( check_num() ) {
				Exp ex( exp );
				ex.work();
				if( ex.error==0 && ex.right )
					ret |= 1;
				if( strcmp( exp, sexp ) == 0 ) ret |= 2;
			}
		}
		printf( "Case %d:\n", T );
		if( ret == 3 ) puts( "Accepted" );
		else if( ret == 1 ) puts( "Presentation Error" );
		else puts( "Wrong Answer" );
	}
}

