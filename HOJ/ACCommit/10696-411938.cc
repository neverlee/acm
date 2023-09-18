#include<cstdio>
#include<cstring>
int f[400000], len, vlen;
char o; int dx, dy;
int getsum( int pos, int ivs, int ive ) {
    if( ive<=dx || ivs>=dy ) return 0;
    if( dx<=ivs && ive<=dy ) return f[pos];
    return getsum( pos*2, ivs, (ive+ivs)/2 )
            + getsum( pos*2+1, (ive+ivs)/2, ive );
}
int main() {
    scanf( "%d", &len );
    for( vlen=1; vlen<len; vlen<<=1 );
    for( int i=0, *p=f+vlen; i<len; ++i )
        scanf( "%d", p++ );
    for( int i=vlen-1; i>0; --i ) f[i] = f[i*2]+f[i*2+1];
    while( 3 == scanf( " %c%d%d", &o, &dx, &dy ) ) {
        if( o==\'a\' ) {
            for( int dd=vlen+dx-1; dd>0; dd>>=1 ) f[dd]+=dy;
        }else if( o==\'q\' ) {
            ++dy;
            printf( "%d\n", getsum( 1, 1, vlen+1 ) );
        }else return 0;
    }
}