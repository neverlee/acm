#include<cstdio>
int s,m,l, s2,m2,k,k2;
int Gcd(int a, int b){int t;while(b){t=a%b;a=b;b=t;}return a;}
int main(){
    for(s=10;s<100;++s){
        for(m=10;m<100;++m){
            for(l=1;l<10;++l){
                if( l==s%10&&l==s/10&&l==m%10&&l==m/10 )continue;
                s2=s*10+l;m2=l*100+m;
                k=Gcd(s,m);
                k2=Gcd(s2,m2);
                if( s/k==s2/k2 && m/k==m2/k2 )
                    printf("%ld / %ld = %ld / %ld\n",s2,m2,s,m);
            }
        }
    }
}
