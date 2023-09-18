#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

char syb[10], exp[2000], ref[26];
int ls;

void init() {
    memset( ref, -1, sizeof(ref) );
    ls = strlen( syb );
    for( int i=0; syb[i]; ++i )
        ref[ syb[i]-\'A\' ] = ls-i-1;
}

const char cmp[6][7] = {
    ">><<>>",
    ">><<>>",
    ">>><>>",
    "<<<<=>",
    "<<<<<>",
    "<<<<<="
};

char trans( char o ) {
    switch(o) {
        case \'&\': return 0;
        case \'|\': return 1;
        case \'~\': return 2;
        case \'(\': return 3;
        case \')\': return 4;
        case \'#\': return 5;
        default : return 6;
    }
}

vector<char> vexp;
void mtor() {
    vexp.clear();

    stack<char> sc;
    sc.push( 5 );

    char *p=exp;
    while( !sc.empty() ) {
        while( isspace(*p) ) ++p;
        if( isupper(*p) ) {
            vexp.push_back(*p);
        }else {
            char o = trans(*p);
            //if( o==6 ) break;
            switch( cmp[ sc.top() ] [ o ] ) {
                case \'>\':
                    vexp.push_back( sc.top() );
                    sc.pop();
                    --p;
                    break;
                case \'<\':
                    sc.push(o);
                    break;
                case \'=\':
                    sc.pop();
                    break;
            }
        }
        ++p;
    }
}

int id, cnt;
char get_val( char o ) {
    o-=\'A\';
    if( ref[o]==-1 ) return 1;
    return (id>>ref[o])&1;
}

void calulgc() {
    int ie=1<<ls;
    cnt = 0;
    for( id=0; id<ie; ++id ) {
        vector<char> ve = vexp;
        for( int i=0, top=-1; i<ve.size(); ++i ) {
            if( isupper(ve[i]) ) {
                ve[++top] = get_val( ve[i] );
            }else {
                if( ve[i]==2 ) ve[top]=!ve[top];
                else {
                    --top;
                    if( ve[i]==0 ) ve[top] &= ve[top+1];
                    else ve[top] |= ve[top+1];
                }
            }
        }
        cnt += ve[0];
        for( int i=ls-1; i>=0; --i )
            printf( "%c ", ((id>>i)&1)?\'T\':\'F\' );
        printf( "|| %c\n", ve[0]?\'T\':\'F\' );
    }
}

int main() {
    while( gets(syb) ) {
        gets( exp );
        for( int i=0; i<syb[i]; ++i )
            printf( "%c ", syb[i] );
        printf( "|| %s\n", exp );
        strcat( exp, "#" );
        init();
        mtor();
        calulgc();
        printf( "Sentence is " );
        if( cnt==(1<<ls) )
            puts( "valid" );
        else puts( "not valid" );
    }
}
