#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int shelf, used;
    char op;
    int arg1, arg2;
    int book[110];
    vector<int>::iterator it;
    for (int t=1; scanf("%d", &shelf), ~shelf; ++t) {
        vector<int> vi;
        used = 0;
        bool work = 1;
        while (work) {
            scanf(" %c", &op);
            switch(op) {
                case \'R\':
                    scanf("%d", &arg1);
                    for (it=vi.begin(); it!=vi.end(); ++it) {
                        if (*it == arg1) {
                            used -= book[*it];
                            vi.erase(it);
                            break;
                        }
                    }
                    break;
                case \'A\':
                    scanf("%d%d", &arg1, &arg2);
                    book[arg1] = arg2;
                    used += arg2;
                    while (used>shelf) {
                        used -= book[vi[0]];
                        vi.erase(vi.begin());
                    }
                    vi.push_back(arg1);
                    break;
                case \'E\':
                    work = 0;
                    break;
            }
        }
        printf("PROBLEM %d:", t);
        
        for (int i=vi.size()-1; i>=0; --i) {
            printf(" %d", vi[i]);
        }
        puts("");
    }
}