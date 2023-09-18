#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Treasure {
    int value;
    int weight;
};

int sort_cmp(const Treasure &ta, const Treasure &tb) {
    return ta.value>tb.value;
}

int main() {
    int n, w, ret;
    Treasure ts[1000];
    scanf("%d%d", &n, &w);
    for (int i=0; i<n; ++i) {
        scanf("%d%d", &ts[i].value, &ts[i].weight);
    }
    sort(ts, ts+n, sort_cmp);
    ret = 0;
    for (int i=0; i<n; ++i) {
        if (w>=ts[i].weight) {
            ret += ts[i].value*ts[i].weight;
            w -= ts[i].weight;
        } else {
            ret += ts[i].value*w;
            break;
        }
    }
    printf("%d", ret);

    return 0;
}
