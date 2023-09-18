#include <stdio.h>

int main() {
    int i, n, k;
    scanf("%d", &n);
    char s[5][6];
    while(n--) {
        for (i=0; i<5; ++i) {
            scanf("%s", s[i]);
        }
        if (s[4][4]==\'%\') k=6;
        else if (s[4][1]==\'&\') k=2;
        else if (s[3][2]==\'%\') k=4;
        else if (s[0][1]==\'%\') k=5;
        else if (s[0][2]==\'&\') k=3;
        else k=1;
        putchar(\'0\'+k);
    }
    return 0;
}