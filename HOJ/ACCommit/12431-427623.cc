#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main() {
    int T;
    map<string, int> mym;
    map<string, int>::iterator it;
    int n, gd;
    char str[300];
    scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &n );
        while( n-- ) {
            scanf( "%d%s", &gd, str );
            string ss(str);
            if( mym.find( ss ) == mym.end() )
                mym[ss] = gd;
            else mym[ss] += gd;
        }
    }
    int imm=0;
    for( it=mym.begin(); it!=mym.end(); ++it )
        if( it->second > imm )
            imm = it->second;
    for( it=mym.begin(); it!=mym.end(); ++it )
        if( it->second == imm )
            puts( (it->first).c_str() );        
}