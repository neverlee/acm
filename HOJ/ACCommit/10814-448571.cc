#include <cstdio>
#include <algorithm>
using namespace std;

struct wood_t {
    int weight, length;
};

int amount;
const int SIZE = 5010;
wood_t woods[SIZE];
int f[SIZE];

int shorter(const wood_t &wa, const wood_t &wb) {
    return  wa.length < wb.length || ( wa.length == wb.length
            && wa.weight < wb.weight ) ;
}

int main() {
    int ncase;
    scanf("%d", &ncase);
    while (ncase--) {
        scanf("%d", &amount);
        for (int i=0; i<amount; ++i) {
            scanf("%d%d", &woods[i].length, &woods[i].weight);
        }
        sort(woods, woods+amount, shorter);

        f[0] = 1;
        for (int i=1; i<amount; ++i) {
            f[i] = 1;
            for (int j=0; j<i; ++j) {
                if (woods[j].weight > woods[i].weight && f[j] >= f[i]) {
                    f[i] = f[j] + 1;
                }
            }
        }
        for (int i=1; i<amount; ++i) {
            f[i] = f[i]>f[i-1]?f[i]:f[i-1];
        }
        printf("%d\n", f[amount-1]);
    }
}