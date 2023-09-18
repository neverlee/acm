#include <cstdio>

int main() {
    int len;
    while (~scanf("%d", &len)) {
        int half = len/2;
        int space, star;

        space = len-1;
        star = 1;
        for (int i=0; i<=half; ++i) {
            for (int k=0; k<space; ++k) putchar(\' \');
            for (int k=0; k<star; ++k) putchar(\'*\');
            puts("");
            space -= 2;
            star += 2;
        }

        space = 2;
        star = len-2;
        for (int i=1; i<=half; ++i) {
            for (int k=0; k<space; ++k) putchar(\' \');
            for (int k=0; k<star; ++k) putchar(\'*\');
            puts("");
            space += 2;
            star -= 2;
        }
        puts("");
    }
}