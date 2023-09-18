#include <cstdio>
#include <memory>
using namespace std;
int a[221][11][221];
int main(){
    int m,n,k;
    while(scanf("%d %d %d", &m, &n, &k) != EOF){
        for (int i = 1; i <= m; ++i)a[i][1][i] = 1;
        for (int i = 2; i <= m; ++i){
            for(int j = 2; j <= n; ++j){
                int nMax1 = i/j;
                for(int p = 1; p <= nMax1; ++p){
                    int nMax2 = (i-p)/(j-1);
                    for (int q = p; q <= nMax2; ++q){
                        a[i][j][p] += a[i-p][j-1][q];
                    }
                }
            }
        }
        int q = m;
        int nCurMin = 1;
        for (int i = 1; i <= n; ++i){
            int p = nCurMin;
            while (a[q][n+1-i][p] < k){
                k -= a[q][n+1-i][p];
                ++p;
            }
            q -= p;
            nCurMin = p;
            if (i == 1)printf("%d",p);
            else printf(" %d",p);
        }
        printf("\n");
    }
    return 0;
}
