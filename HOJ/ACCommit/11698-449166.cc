#include <cstdio>
#include <cstring>

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        char name[12], s[12];
        double mx = 0;
        int mass, auger;
        while (n--) {
            scanf("%s %d %d", s, &mass, &auger);
            double x = (double)auger*auger/mass;
            if (x>mx) {
                mx = x;
                strcpy(name, s);
            }
        }
        puts(name);
    }
}