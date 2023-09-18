#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int DAY = 100010;

int len, day;
int d[DAY], pn[DAY];

void init_next() {
    int f[DAY];
    memset(f, -1, sizeof(f));
    for (int i=day-1; i>=0; --i) {
        int n = d[i];
        pn[i] = f[n];
        f[n] = i;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &len, &day);
        for (int i=0; i<day; ++i) {
            scanf("%d", d+i);
        }
        init_next();

        int find = 0;
        vector<int> shelf;
        for (int i=0; i<day; ++i) {
            int k = -1, max = 0;
            for (int j=0; j<shelf.size(); ++j) {
                if (d[shelf[j]] == d[i]) {
                    k = i;
                    shelf[j] = i;
                    break;
                }
            }

            if (k == -1) {
                ++find;
                if (shelf.size() < len) {
                    shelf.push_back(i);
                } else {
                    for (int j=0; j<shelf.size(); ++j) {
                        int r = shelf[j];
                        if (pn[r] == -1) {
                            k = j;
                            break;
                        } else if (pn[r]-i >= max) {
                            max = pn[r]-i;
                            k = j;
                        }
                    }
                    shelf[k] = i; 
                }
            }
        }
        printf("%d\n", find);
    }
}