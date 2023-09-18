#include <cstdio>
#include <cstring>

int main() {
    int t;
    char w[110], s[1010];
    scanf("%d%*c", &t);
    while (t--) {
        gets(w);
        gets(s);
        int n = 0, l;
        l = strlen(w);
        for (int i=0; s[i]; ++i) {
            n += !strncmp(s+i, w, l);
        }
        printf("%d\n", n);
    }
}