#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define NUM(n)   ((0x0000000f)&(n))
#define FLUSH(n) ((0x00000030)&(n))

struct Card{
    int bn[5], bf[5];
    int args[6];
    void build( char *str ) {
        const static char snum[] = "23456789TJQKA";
        const static char sflh[] = "CDHS";
        int i, n, f, k;
        for( i=0; i<5; ++i ) {
            while( *str<\'0\' ) ++str;
            for( k=0; k<13; ++k ) if( *str==snum[k] ) n=k+2;
            *str++=\' \';
            for( k=0; k<4; ++k ) if( *str==sflh[k] ) f=k;
            *str++=\' \';
            bn[i] = bf[i] = (f<<4)+n;
        }
        sort( bn, bn+5, cmpNF );
        sort( bf, bf+5, cmpFN );
        args[5]=0;
    }
    static bool cmpNF( const int &a, const int &b ) {
        int ca, cb;
        ca = (NUM(a)<<6)+FLUSH(a);
        cb = (NUM(b)<<6)+FLUSH(a);
        return ca<cb;
    }
    static bool cmpFN( const int &a, const int &b ) { return a<b; }
    void ckStraightFlush() {
        int sg, flh, i;
        int f[5];
        for( i=0; i<5; ++i ) f[i]=NUM(bn[i]);
        for( i=0, sg=f[0]; i<5; ++i, ++sg )
            if( f[i]!=sg ) {
                sg=0;
                break;
            }
        flh = FLUSH(bf[0])==FLUSH(bf[4]);
        if( sg>0 && flh>0 ) args[5] = 9;
        else if( flh>0 ) args[5] = 6;
        else if( sg>0 ) args[5] = 5;
        if( args[5]!=0 ) {
            for( i=0; i<5; ++i )
                args[i] = f[i];
        }
    }
    void ckFour() {
        int i;
        if( NUM(bn[0])==NUM(bn[3]) || NUM(bn[1])==NUM(bn[4]) ) {
            args[5] = 8;
            for( i=0; i<5; ++i ) args[i] = NUM(bn[i]);
            if( args[0]==args[3] ) swap( args[0], args[4] );
        }
    }
    void ckThree() {
        int f[5], i, c, k;
        for( i=0; i<5; ++i ) f[i]=NUM(bn[i]);
        if( f[0]==f[2] || f[1]==f[3] || f[2]==f[4] ) {
            for( i=4; i>1; --i ) args[i] = f[2];
            for( i=0, c=0, k=f[2]; c<3&&i<5; ++i )
            if( f[i]==k ) {
                ++c; f[i]=0;
            }
            sort( f, f+5 );
            args[0] = f[3];
            args[1] = f[4];
            if( args[0]==args[1] ) args[5] = 7;
            else args[5] = 4;
        }
    }
    int getPair( int *ay ) {
        for( int i=0; i<4; ++i )
            if( ay[i]>0 && ay[i]==ay[i+1] ) {
                int ret=ay[i];
                ay[i]=ay[i+1]=0;
                return ret;
            }
        return 0;
    }
    void ckPairs() {
        int f[5], i, j;
        for( i=0; i<5; ++i ) f[i] = NUM( bn[i] );
        int pa, pb;
        pa = getPair( f );
        pb = getPair( f );
        if( pb>pa ) swap(pa,pb);
        if( pa>0 ) {
            if( pb>0 ) args[5]=3;
            else args[5]=2;
            args[3] = args[4] = pa;
            args[1] = args[2] = pb;
            sort( f, f+5 );
            if( pb>0 ) i=4;
            else i=2;
            for( j=0; i<5; ++i,++j )
                args[j]=f[i];
        }
    }
    void ckHigh() {
        args[5]=1;
        for( int i=0; i<5; ++i )
            args[i] = NUM(bn[i]);
    }
    void setRank() {
        args[5]=0;
        ckStraightFlush();
        if( args[5]<8 ) ckFour();
        if( args[5]<7 ) ckThree();
        //Flush
        //Straight
        //Three
        if( args[5]<3 ) ckPairs();
        //Single pair
        if( args[5]<1 ) ckHigh();
    }
    static int cmpWith( const Card &ca, const Card &cb ) {
        int i;
        for( i=5; i>=0; --i )
            if( ca.args[i]!=cb.args[i] )
                return ca.args[i]-cb.args[i];
        return 0;
    }
    void output() {
        int i;
        for( i=0; i<5; ++i )
            printf( "%d:%2d  ", FLUSH(bn[i])>>4, NUM(bn[i]) );
        puts("");
        for( i=0; i<6; ++i )
            printf( "%3d ", args[i] );
        printf("\n");
    }
};
int main() {
    char str[100];
    Card ca, cb;
    while( gets(str) ) {
        ca.build(str); cb.build(str);
        ca.setRank();
        cb.setRank();
        //ca.output(); cb.output();
        int ret = Card::cmpWith( ca, cb );
        if( ret>0  ) puts("Black wins.");
        if( ret<0  ) puts("White wins.");
        if( ret==0 ) puts("Tie.");
    }
}