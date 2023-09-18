#include <stdio.h>

int main() {
    int a, b, c;
    while (EOF != scanf("%d%d%d", &a, &b, &c)) {
        printf("%s\n", a+b>=c?"Yes":"No");
    }
    return 0;
}