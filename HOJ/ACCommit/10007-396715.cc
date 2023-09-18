#include <stdio.h>
#include <stdlib.h>
typedef unsigned __int64 uint;
#define MAX 100

uint len, dig, limit;
uint mod(uint a, uint b, uint n){
    if(! a) return 0;
    return (((a&dig)*b)%n + (mod(a>>len,b,n)<<len)%n) % n;
}

uint by(uint a, uint b, uint n){
    uint p;
    p = 8, len = 61;
    while(p < n){
        p <<= 4;
        len -= 4;
    }
    dig = ((limit / p) << 1) - 1;
    return mod(a, b, n);
}

uint random(){uint a;a=rand();a*=rand();a*=rand();a*=rand();return a;}

uint square_multiply(uint x, uint c, uint n){
    uint z = 1;
    while(c > 0){
        if(c % 2 == 1) z = by(z, x, n);
        x = by(x, x, n);
        c = (c >> 1);
    }
    return z;
}

bool Miller_Rabin(uint n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(! (n & 1))return false;
    uint k = 0, i, j, m, a;
    m = n - 1;
    while(m % 2 == 0)
    {
        m =(m >> 1);
        k++;
    }
    for(i = 0; i < MAX; i++)
    {
        a = square_multiply(random() % (n - 1) + 1, m, n);
        if(a == 1) continue;
        for(j = 0; j < k; j++)
        {
            if(a == n - 1) break;
            a = by(a, a, n);
        }
        if(j < k) continue;
        return false ;
    }
    return true;
}

uint gcd(uint a, uint b){
    return b == 0 ? a : gcd(b, a % b);
}

uint calc(uint x, uint n ){
    return (by(x, x, n) + 1) % n;
}

uint Pollard(uint n)
{
    if(n <= 2) return 0;
    if(! (n & 1)) return 2;
    uint i, p, x,xx;
    for(i = 1; i < MAX; i++)
    {
        x = random() % n;
        xx = calc(x, n);
        p = gcd((xx + n - x) % n, n);
        while(p == 1)
        {
            x = calc(x, n);
            xx = calc(calc(xx, n), n);
            p = gcd((xx + n - x) % n, n) % n;
        }
        if(p) return p;
    }
    return 0;
}

uint prime(uint a){
    if(Miller_Rabin(a)) return 0;
    uint t = Pollard(a), p;
    if(p = prime(t))return p;
    else return t;
}

int main()
{
    uint p, t, n, min;
    limit = 1;
    limit = limit << 63;
    scanf("%I64u", &t);
    while(t--) {
        scanf("%I64u", &n);
        min = n;
        if(Miller_Rabin(n)) printf("Prime\n");
        else{
            while(n > 1) {
                if(Miller_Rabin(n))break;
                p = prime(n);
                if(p < min) min = p;
                n /= p;
            }
            if(min > n) min = n;
            printf("%I64u\n", min);
        }
    }
    return 0;
}