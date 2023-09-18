#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
    int x,y;
}dic;
dic d[1001];

double cal(double x1,double y1,double x2,double y2) {
    return (y2-y1)/(x2-x1);
}

int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0)
            return 0;
        int i,j,sum,max,lab,flag=0;
        double k[1001];
        for (i=0; i<n; i++)
            scanf("%d%d",&d[i].x,&d[i].y);
        for (i=0; i<n-1; i++) {
            sum=0;
            for (j=i+1; j<n; j++)
                k[sum++]=cal(d[i].x,d[i].y,d[j].x,d[j].y);
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
