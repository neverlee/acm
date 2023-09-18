#include<cstdio>
int num, t2, t3, tl;
int main() {
    while( scanf( "%d", &num ), num ) {
        num%=28;
        t2=2;t3=3;tl=22;
        for( int i=0; i<num; ++i ) {
            t2=t2*4%29;
            t3=t3*3%29;
            tl=tl*22%29;
        }
        num = (t2-1)*(t3-1)*(tl-1)%29;
        printf( "%d\n", num*9%29 );
    }
}