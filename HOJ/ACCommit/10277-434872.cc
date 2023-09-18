#include <cstdio>
#include <cstring>

const int SZ = 101;
const int N = 500;
struct Student{
    int high;
    char sex;
    char music[SZ];
    char sport[SZ];
}stds[N];
int amount, nboy, ngirl;

int pid[N], first[N];
int lkt[N*N], next[N*N], nlk;

void init() {
    memset( first, -1, sizeof(first) );
    for( int i=0, b=0, g=nboy; i<amount; ++i ) {
        if( stds[i].sex==\'F\' ) {
            pid[b++] = i;
        }else pid[g++] = i;
    }
    nlk = 0;
    Student *sa, *sb;
    for( int i=0; i<nboy; ++i )
        for( int j=nboy; j<ngirl; ++j ) {
            sa = stds+pid[i]; sb = stds+pid[j];
            if( ( sa->high-sb->high<=40 && sa->high-sb->high>=-40 )
                    && strcmp( sa->music, sb->music )==0
                    && strcmp( sa->sport, sb->sport ) ) {
                next[nlk] = first[i];
                first[i] = nlk;
                lkt[nlk] = j;
                ++nlk;
            }
        }
}

bool used[N]; int lky[N];
bool can( int t ) {
    int pt = first[t], y;
    for( int pt=first[t]; pt!=-1; pt=next[pt] ) {
        y = lkt[pt];
        if( used[y]==0 ) {
            used[y] = 1;
            if( lky[y]==-1 || can( lky[y] ) ) {
                lky[y] = t;
                return 1;
            }
        }
    }
    return 0;
}
int match() {
    int ret=0;
    memset( lky, -1, sizeof(lky) );
    for( int i=0; i<nboy; ++i ) {
        memset( used, 0, sizeof(used) );
        if( can(i) ) {
            ++ret;
        }
    }
    return ret;
}

int main() {
    int T; scanf( "%d", &T );
    while( T-- ) {
        scanf( "%d", &amount );
        nboy = ngirl = 0;
        for( int i=0; i<amount; ++i ) {
            scanf( "%d %c %s %s", &stds[i].high, &stds[i].sex
                    , stds[i].music, stds[i].sport );
            if( stds[i].sex==\'F\' ) ++nboy;
            else ++ngirl;
        }
        ngirl += nboy;
        init();
        printf( "%d\n", ngirl-match() );
    }
}











