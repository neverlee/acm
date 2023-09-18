#include <cstdio>
#include <cstring>

char src[1010], tag[110];
int next[110], nvx[1010];
int ls, lt, cnt;

void get_next() {
    next[0] = -1;
    int i, j;
    for( i=1, j=0; i<lt; ) {
        if( tag[i]==tag[j] || j==-1 ) {
            ++i; ++j;
            if( tag[i]!=tag[j] ) next[i] = j;
            else next[i] = next[j];
        }else j=next[j];
    }
}

void kmp_idx() {
    int i=0, j=0;
    while( i<=ls ) {
        if( j==-1 || src[i]==tag[j] ) {
            ++i; ++j;
            if( j==lt ) {
                nvx[++cnt] = i-j;
                j=next[j];
            }
        }else j = next[j];
    }
    nvx[0] = -lt;
}

int fx[1010], fi[1010];
void dp() {
    if( cnt==0 ) {
        puts( "0 0" );
        return;
    }
    fx[0] = fi[0] = 0;
    for( int i=1; i<=cnt; ++i ) {
        int k=i-1;
        while( nvx[k]+lt>nvx[i] ) --k;
        fx[i] = fx[k]+1;
        fx[i] = fx[i]>fx[i-1]?fx[i]:fx[i-1];
        fi[i] = fi[k];
        for( int p=k-1; nvx[p]+lt>nvx[k] && p>0; --p )
            fi[i] = fi[i]<fi[p]?fi[i]:fi[p];
        ++fi[i];
    }
    int k=cnt-1;
    while( nvx[k]+lt>nvx[cnt] ) {
        fi[cnt] = fi[cnt]<fi[k]?fi[cnt]:fi[k];
        --k;
    }
    printf( "%d %d", fi[cnt], fx[cnt] );
}

int main() {
    scanf( "%s%s", tag, src );
    ls = strlen( src );
    lt = strlen( tag );
    strcat( tag, "#" );
    get_next();
    kmp_idx();
    dp();
}