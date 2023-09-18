#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#include <vector>
using namespace std;

char exp[200], str[200];

void init_exp() {
    int i, j;
    for( i=0, j=0; str[i]; ++i,++j ) {
        if( (str[i]==\'+\'||str[i]==\'-\') && ( i==0 || str[i-1]==\'(\' ) )
            exp[j++] = \'0\';
        exp[j] = str[i];
    }
    exp[j] = 0;
    strcat( exp, "#" );
}

void change() {
    const int OPT = 1000000;
    stack<char> sc;
    sc.push( \'#\' );
    vector<int> ret;
    char *p = exp;
    
    while( !sc.empty() ) {
        while( *p==\' \' ) ++p;
        if( isdigit( *p ) ) {
            ret.push_back( *p-\'0\' );
        }else if( *p==\'#\' || *p==\')\' ) {
            char o=\'#\';
            if( *p==\')\' ) o = \'(\';
            while( sc.top()!=o ) {
                ret.push_back( sc.top()+OPT );
                sc.pop();
            }
            sc.pop();
        }else if( *p==\'(\' || sc.top()==\'(\' || sc.top()==\'#\' ) {
            sc.push( *p );
        }else {
            ret.push_back( sc.top()+OPT );
            sc.pop();
            --p;
        }
        ++p;
    }
    for( int i=0, top=-1; i<ret.size(); ++i ) {
        if( ret[i]<OPT ) ret[++top] = ret[i];
        else {
            char o = ret[i]-OPT;
            if( o==\'+\' ) ret[top-1] += ret[top];
            else ret[top-1] -= ret[top];
            --top;
        }
    }
    printf( "%d\n", ret[0] );
}


int main() {
    while( gets( str ) ) {
        init_exp();
        change();
    }
}
