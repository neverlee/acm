#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1001;
int x[N],y[N];

int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0)
            return 0;
        int i,j,sum,max,lab,flag=0;
        double k[N];
        for (i=0; i<n; i++)
            scanf("%d%d", x+i, y+i );
        for (i=0; i<n-1; i++) {
            sum=0;
            for (j=i+1; j<n; j++)
                k[sum++]=((double)y[j]-y[i])/((double)x[j]-x[i]);
            sort(k, k+sum);
            lab = 1; max = 1;
            for (j=1; j<sum; j++) {
                if (k[j]==k[j-1]) {
                    ++lab;
                }else {
                    max = max>lab?max:lab;
                    lab=1;
                }
            }
            max = max>lab?max:lab;
            flag = flag>max?flag:max;
        }
        printf("%d\n",flag+1);
    }
    return 0;
}
