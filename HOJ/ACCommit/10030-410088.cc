#include <cstdio>
#include <stack>
#include <cctype>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

const char cmp[8][8] = {//>\xb5\xaf <\xd1\xb9
    //+      -    *   ^    (   )    0
    {\'>\',\'>\',\'<\',\'<\',\'<\',\'>\',\'>\'},// +
    {\'>\',\'>\',\'<\',\'<\',\'<\',\'>\',\'>\'},// -
    {\'>\',\'>\',\'>\',\'<\',\'<\',\'>\',\'>\'},// *
    {\'>\',\'>\',\'>\',\'>\',\'<\',\'>\',\'>\'},// ^
    {\'<\',\'<\',\'<\',\'<\',\'<\',\'=\',\'>\'},// (
    {\'>\',\'>\',\'>\',\'>\',\'>\',\'X\',\'>\'},// )
    {\'<\',\'<\',\'<\',\'<\',\'<\',\'<\',\'=\'} // 0
};
int trans(char c) {
    switch(c) {
    case \'+\': return 0;
    case \'-\': return 1;
    case \'*\': return 2;
    case \'^\': return 3;
    case \'(\': return 4;
    case \')\': return 5;
    case 0  : return 6;
    }
}
__int64 acalu( __int64 a, __int64 b, __int64 o ) {
    __int64 d;
    switch(o) {
    case 0: return a+b;
    case 1: return a-b;
    case 2: return a*b;
    case 3:
        for( d=1; b--; d*=a );
        return d;
    }
}

stack<char> opt;
char sexp[400], *p;
vector<__int64> onum;
vector<bool> type;
__int64 getInt() {
    __int64 k=0;
    for( ; isdigit(*p); ++p )
        k = k*10+*p-\'0\';
    return k;
}

void init() {
    onum.reserve( 200 );
    type.reserve( 200 );
}

__int64 caluExp( __int64 var ) {
    p = sexp;
    while( !opt.empty() ) opt.pop();
    onum.clear();
    type.clear();
    
    opt.push(6);
    __int64 dn;
    char o;
    while( !opt.empty() ) {
        while( isspace(*p) ) ++p;
        if( isdigit(*p) || *p==\'a\') {
            if( *p==\'a\' ) {
                dn = var;
                ++p;
            }else dn = getInt();
            onum.push_back( dn );
            type.push_back( 0 );
        }else {
            o = trans(*p);
            switch( cmp[opt.top()][o] ) {
            case \'<\':
                opt.push( o );
                ++p;
                break;
            case \'=\':
                ++p;
                opt.pop();
                break;
            case \'>\':
                dn = opt.top();
                opt.pop();
                //if( dn>3 ) break;
                onum.push_back( dn );
                type.push_back( 1 );
                break;
            case \'X\':
                ++p;
                break;
            }
        }
    }
    int i, top;
    for( i=0, top=-1; i<onum.size(); ++i ) {
        if( type[i]&&onum[i]<4 ) {
            onum[top-1] = acalu( onum[top-1], onum[top], onum[i] );
            --top;
        }else if( type[i]==0 ) onum[++top] = onum[i];
    }
    return onum[0];
}

void work() {
    __int64 src;
    int i, ne;
    gets( sexp );
    src = caluExp( 23 );
    scanf( "%d", &ne );
    getchar();
    for( i=0; i<ne; ++i ) {
        gets( sexp );
        if( src == caluExp( 23 ) ) {
            putchar(i+\'A\');
        }
    }
}
int main() {
    init();
    work();
    return 0;
}