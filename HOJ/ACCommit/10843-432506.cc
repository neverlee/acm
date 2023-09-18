#include <cstdio>
#include <cstring>

bool mut[26][26]={0}, week[26]={0};
int all, link, rct;

void init() {
    char ss[5];
    scanf( "%d%d", &all, &link );
    scanf( "%s", ss );
    for( int i=0; ss[i]; ++i ) week[ ss[i]-\'A\' ] = 1;
    char a,b;
    for( int i=0; i<link; ++i ) {
        scanf( "%s", ss );
        a = ss[0]-\'A\';
        b = ss[1]-\'A\';
        mut[a][b] = 1;
        mut[b][a] = 1;
    }
    rct = 3;
}

void work() {
    int need=0;
    bool w[26];
    while( rct<all ) {
        bool get=0;
        memcpy( w, week, 26 );
        for( int i=0; i<26; ++i )
        if( week[i]==0 ) {
            int c=0;
            for( int j=0; j<26; ++j )
                if( week[j] && mut[i][j] )
                    ++c;
            if( c>=3 ) {
                w[i] = 1;
                get = 1;
                ++rct;
            }
        }
        if( get==0 ) break;
        memcpy( week, w, 26 );
        ++need;
    }
    if( rct==all ) printf( "WAKE UP IN %d YEARS", need );
    else puts("THIS BRAIN NEVER WAKES UP");
}

int main() {
    init();
    work();
}
