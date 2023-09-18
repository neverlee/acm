#include <cstdio>
int main() {
    int n;
    while( ~scanf("%d", &n) ) {
        int i = 1;
        int count = 0;
        do{
            if(i <= n) i = 2 * i;
            else i = (i-n)*2-1;
            ++count;
        }while(i != 1);
        printf("%d\n", count);
    }
}
