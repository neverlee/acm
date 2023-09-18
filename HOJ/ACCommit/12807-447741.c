#include <stdio.h>

int main() {
    char s[30];
    while (EOF != scanf("%s", s)) {
        int ny=0, my=0, r=0, i;
        for (i=0; s[i]; ++i) {
            if (s[i] == \'Y\') {
                ++ny;
                ++r;
            } else if (s[i] == \'X\') {
                ++r;
            } else { 
                my = r>my?r:my;
                r = 0;
            }
        }
        my = r>my?r:my;
        printf("%d %d\n", ny, my);
    }
    return 0;
}