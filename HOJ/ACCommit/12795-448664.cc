#include <cstdio>
#include <cstring>
#include <cctype>
#include <stack>
#include <map>
#include <string>
using namespace std;

char src[120];
int x;
map<string, int> nodes;

int get_number() {
    int n = 0, k = 1;
    while (x>=0 && isdigit(src[x])) {
        n = k*(src[x]-\'0\');
        --x;
        k *= 10;
    }
    return n;
}

void set_node(int count) {
    char *end, *start;
    end = src + x + 1;
    while (islower(src[x--]));
    start = src + x + 1;
    string ele(start, 0, end-start);
    if (nodes.find(ele) != nodes.end()) {
        count += nodes[ele];
    }
    nodes[ele] = count;
}

void work() {
    stack<int> si;
    int multi = 1;
    int status = 0;
    nodes.clear();
    while (x>=0) {
        if (isdigit(src[x])) {
            int n = get_number();
            si.push(n);
            status = 1;
        } else if (isalpha(src[x])) {
            int n;
            if (status == 1) {
                n = multi * si.top();
                si.pop();
            } else {
                n = multi;
            }
            set_node(n);
            status = 0;
        } else if (src[x] == \')\') {
            --x;
            if (status == 0) {
                si.push(1);
            }
            multi *= si.top();
            status = 0;
        } else if (src[x] == \'(\') {
            --x;
            multi /= si.top();
            si.pop();
            status = 0;
        } else {
            --x;
        }
    }
    map<string, int>::iterator it;
    for (it=nodes.begin(); it!=nodes.end(); ++it) {
        if (it!=nodes.begin()) {
            putchar(\'+\');
        }
        if (it->second>1) {
            printf("%d", it->second);
        }
        printf("%s", it->first.c_str());
    }
    puts("");
}

int main() {
    while (gets(src)) {
        x = strlen(src) - 1;
        work();
    }
}