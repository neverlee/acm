#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

const int SIZE = 501001;
const int LEN = 10;
char name[SIZE][LEN+1];
int have[SIZE];
int mst[SIZE];
int code[LEN];
void initial() {
    for( int i=0; i<SIZE; ++i )
        mst[i] = i;
    srand( time( NULL ) );
    for( int i=0; i<LEN; ++i )
        code[i] = rand()*rand()%SIZE;
}
int find( int px ) {
    if( px != mst[px] ) mst[px] = find( mst[px] );
    return mst[px];
}
void mst_union( int px, int py ) {
    px = find(px);
    py = find(py);
    mst[px] = py;
}
int hash_code( char *s ) {
    int sum=0;
    for( int i=0; i<LEN&&s[i]; ++i )
        sum += code[i]*s[i];
    sum %= SIZE;
    return sum;
}
int find_string( char *s ) {
    int pos, np;
    pos = hash_code( s );
    for( int i=0; i<SIZE; ++i ) {
        np = (pos+i)%SIZE;
        if( name[np][0]==0 || strcmp( name[np], s ) == 0 ) {
            if( name[np][0]==0 ) strcpy( name[np], s );
            return np;
        }
    }
}
bool check_link() {
    int head=-1;
    for( int i=0;i<SIZE;i++ )
    if( name[i][0] ) {
        int tmp=find(i);
        if( head==-1 || tmp==head ) head=tmp;
        else return false;
    }
    return true;
}
bool check_euler() {
    int i,cit=0;
    for(i=0;i<SIZE;i++)
    if( name[i][0] ) {
        if( have[i]&1 ) ++cit;
    }
    if( cit<3 )return 1;
    else return 0;
}
int main() {
    initial();
    char s1[20], s2[20]; int x, y;
    while( EOF != scanf( "%s%s", s1, s2 ) ) {
        x = find_string(s1);
        y = find_string(s2);
        ++have[x]; ++have[y];
        mst_union(x, y);
    }
    if( check_link() && check_euler() ) puts("Possible");
    else puts("Impossible");
}