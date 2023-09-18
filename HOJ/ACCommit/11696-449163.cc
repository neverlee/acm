#include <cstdio>
#include <algorithm>
using namespace std;

char name[300][20];
double score[300];
int p[300];
int student, credit, sum;
int real;
int dit[10];

bool compare(const int &a, const int &b) {
    return score[a] > score[b];
}

int main() {
    while (2==scanf("%d%d", &student, &credit)) {
        sum = 0;
        for (int i=0; i<credit; ++i) {
            scanf("%d", dit+i);
            sum += dit[i];
        }
        real = 0;
        int s[10];
        while (student--) {
            scanf("%s", name[real]);
            bool good = 1;
            for (int i=0; i<credit; ++i) {
                scanf("%d", s+i);
                if (s[i]<60) {
                    good = 0;
                }
            }

            if (good) {
                int t = 0;
                for (int i=0; i<credit; ++i) {
                    t += dit[i]*s[i];
                }
                score[real] = (double)t/sum;
                ++real;
            }
        }
        for (int i=0; i<real; ++i) {
            p[i] = i;
        }
        sort(p, p+real, compare);
        for (int i=0; i<real; ++i) {
            printf("%d %s %.3lf\n", i+1, name[p[i]], score[p[i]]);
        }
    }
}