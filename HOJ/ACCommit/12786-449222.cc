#include <cstdio>
#include <cstring>

int main() {
    char s[100];
    int n[110], l;

    int max = 0, ret = 0;
    for (l=0; gets(s); ++l) {
        if (s[0] == 0) {
            break;
        }
        n[l] = strlen(s);
        max = n[l]>max?n[l]:max;
    }
    for (int i=l-2; i>=0; i--) {
        ret += (max-n[i])*(max-n[i]);
    }
    printf("%d", ret);
}