#include <cstdio>
#include <cstring>

int main() {
    int n;
    char s[120];
    scanf("%d%*c", &n);
    while (n--) {
        int a = 0, e = 0;
        s[0] = 0;
        while (gets(s)) {
            if (s[0]==0) {
                break;
            }
            for (int i=0; s[i]; ++i) {
                ++a;
                e += s[i]==\'#\';
            }
        }
        sprintf(s, "%.1lf", (a-e)*100.0/a);
        int l = strlen(s);
        if (s[l-1]==\'0\') {
            s[l-2] = 0;
        }
        printf("Efficiency ratio is %s%%.\n", s);
    }
}