#include <cstdio>
#include <cstring>
const int SIZE = 70000;
int amount, mod, blen;

int ff[SIZE];

int main() {
    while( EOF != scanf ("%d%d", &amount, &mod) ) {
        for (blen=1; blen<amount; blen<<=1);
        memset (ff+blen, 0, blen*sizeof(int));
        for (int i=0; i<amount; ++i)
            ff[i+blen] = 1;
        for (int i=blen-1; i>0; --i)
            ff[i] = ff[i<<1]+ff[(i<<1)+1];
        int rct=0;
        --mod;
        for ( ;amount ; --amount ) {
            int k, d;
            rct = (rct+mod)%amount;
            for( k=1, d=rct+1; k<blen; ) {
                int dk = k<<1;
                if( ff[dk]<d )
                    d -= ff[dk++];
                k = dk;
            }
            if( amount>1 ) printf( "%d ", k-blen+1 );
            else printf( "%d\n", k-blen+1 );
            for( ; k>0; k>>=1 ) --ff[k];
        }
    }
}
