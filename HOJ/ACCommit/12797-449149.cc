#include <cstdio>
#include <cstring>

const int N=100001;
int amount;
int base;

struct node_t{
    int in, out;
    node_t() {};
    node_t(int i, int o) { in=i; out=o; }
};

node_t left[N];
node_t right[N];

int get_int() {
    char c;
    while ((c=getchar())<\'0\');
    int ret = c-\'0\';
    while ((c=getchar())>=\'0\') {
        ret = ret*10+c-\'0\';
    }
    return ret;
}

node_t merge(const node_t &a, const node_t &b) {
    int t = a.out - b.in;
    if (t>=0) {
        return node_t(a.in, b.out+t);
    } else {
        return node_t(a.in-t, b.out);
    }
}

void initbit() {
    for (int i=0; i<amount; ++i) {
        int t = left[i].in - left[i].out;
        if (t >= 0) {
            left[i].in = 0;
            left[i].out = t;
        } else {
            left[i].in = -t;
            left[i].out = 0;
        }
    }

    right[amount-1] = left[amount-1];
    for (int i=amount-2; i>=0; --i) {
        right[i] = merge(left[i], right[i+1]);
    }
    for (int i=1; i<amount; ++i) {
        left[i] = merge(left[i-1], left[i]);
    }
    for (int i=1; i<amount; ++i) {
        right[i] = merge(right[i], left[i-1]);
    }
}

int main() {
    for (int t=1; amount = get_int(), amount; ++t) {
        for (int i=0; i<amount; ++i) {
            left[i].in = get_int();
        }
        for (int i=0; i<amount; ++i) {
            left[i].out = get_int();
        }
        initbit();
        
        printf("Case %d:", t);
        for (int i=0; i<amount; ++i) {
            if (right[i].in == 0) {
                printf(" %d", i+1);
            }
        }
        puts("");
    }
}