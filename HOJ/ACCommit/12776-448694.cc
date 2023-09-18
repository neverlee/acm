#include <cstdio>
#include <cstring>
#include <cctype>

int main() {
    char s[100] = {0};
    char a[] = "roblem";
    while (gets(s)) {
        bool flag = 0;
        for (int i=0; s[i]; ++i) {
            if ((s[i] == \'p\' || s[i] == \'P\')) {
                if (0==strncasecmp(s+i+1, a, sizeof(a)-1)) {
                    flag = 1;
                    break;
                }
            }
        }
        puts(flag?"yes":"no");
    }
}