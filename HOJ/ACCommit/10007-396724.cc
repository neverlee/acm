#include <stdio.h>
#include <stdlib.h>
typedef unsigned __int64 uint;
#define MAX 100
uint Mod(uint a, uint b, uint n){
    if(!a||!b)return 0;
    return (a*(b&63)+Mod((a<<6)%n, b>>6, n))%n;
}
uint Random(){uint a;a=rand();a*=rand();a*=rand();a*=rand();return a;}
uint PowerMod(uint a, uint k, uint m){
    uint ans=1, temp=a;
    while(k){
        if(k&1)ans=Mod(temp, ans, m);
        temp=Mod(temp, temp, m);
        k>>=1;
    }
    return ans;
}
bool Miller_Rabin(uint n){
    if(n<2) return false;
    if(n==2) return true;
    if(!(n&1))return false;
    uint k = 0, i, j, m, a;
    m=n-1;while(m%2==0){m =(m>>1);k++;}
    for(i=0;i<MAX; i++){
        a = PowerMod(Random() % (n - 1) + 1, m, n);
        if(a==1) continue;
        for(j = 0; j < k; j++){
            if(a == n - 1) break;
            a = Mod(a, a, n);
        }
        if(j < k) continue;
        return false ;
    }
    return true;
}

uint Gcd(uint a, uint b){
    uint t;
    while(b){t=a%b;a=b;b=t;}
    return a;
}
uint Fget(uint x, uint n){return (Mod(x, x, n)+1)%n;}

uint Pollard(uint n)
{
    if(n<=2) return 0;
    if(!(n&1)) return 2;
    uint i, p, x,xx;
    for(i = 1; i < MAX; i++){
        x = Random() % n;
        xx = Fget(x, n);
        p = Gcd((xx + n - x) % n, n);
        while(p == 1){
            x = Fget(x, n);
            xx = Fget(Fget(xx, n), n);
            p = Gcd((xx + n - x) % n, n) % n;
        }
        if(p) return p;
    }
    return 0;
}

uint Prime(uint a){
    if(Miller_Rabin(a)) return 0;
    uint t = Pollard(a), p;
    if(p = Prime(t))return p;
    else return t;
}

int main(){
    uint p, t, n, min;
    scanf("%I64u", &t);
    while(t--) {
        scanf("%I64u", &n);
        min = n;
        if(Miller_Rabin(n)) printf("Prime\n");
        else{
            while(n > 1) {
                if(Miller_Rabin(n))break;
                p = Prime(n);
                if(p < min) min = p;
                n /= p;
            }
            if(min > n) min = n;
            printf("%I64u\n", min);
        }
    }
}