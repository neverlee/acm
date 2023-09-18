#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Point{
    double x, y;
    double dis1, dis2, dis3;
}p[100], cp[6], center;
double res;
const int seq[5][2] = {0, 2, 2, 3, 3, 1, 4, 2, 3, 5};
int n;
#define dis(a, b) ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))
double p_dis_s( Point&a, Point& b, Point& c ) {
    double A = a.y - b.y, B = b.x - a.x;
    double D = a.x * (b.y - a.y) -     a.y * (b.x - a.x);
    double ans = dis(a, c);
    double temp = dis(b, c);
    double xx = (B * B * c.x - A * D - A * B * c.y) / (A * A + B * B);
    if(ans > temp) ans = temp;
    temp = (A * c.x + B * c.y + D) * (A * c.x + B * c.y + D) / (A * A + B * B);
    if(a.x < xx && b.x > xx) return temp;
    else return ans;
}

double find_min(struct Point& a) {
    double ans = 99999.;
    double temp;
    for(int i = 0; i < 5; ++i) {
        temp = p_dis_s(cp[seq[i][0]], cp[seq[i][1]], a);
        if(temp < ans) ans = temp;
    }

    a.dis3 = sqrt(ans);
    return a.dis3;
}

void compute() {
    double sum;
    double temp;
    int i, j;
    sum = 0;
    for(i = 0; i < n; ++i) {
        sum += find_min(p[i]);
        p[i].dis1 = sqrt(dis(cp[2], p[i]));
        p[i].dis2 = sqrt(dis(cp[3], p[i]));
    }
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            if( i!=j ){
                temp = sum - p[i].dis3 - p[j].dis3 + p[i].dis1 + p[j].dis2;
                if(temp < res)
                    res = temp;
            }
}

int main() {
    cp[0].x = 0., cp[0].y = 1., cp[1].x = 1., cp[1].y = 1.;
    cp[2].x = sqrt(3.) / 6, cp[2].y = 0.5, cp[3].x = 1 - sqrt(3.) / 6, cp[3].y = 0.5;
    cp[4].x = 0., cp[4].y = 0., cp[5].x = 1., cp[5].y = 0;
    center.x = 0.5, center.y = 0.5;
    int i;
    while( scanf("%d", &n), n ) {
        for(i = 0; i < n; ++i)
            scanf("%lf %lf", &(p[i].x), &(p[i].y));
        if(n == 1) {
            printf("%.3lf\n", sqrt(dis(center, p[0])));
            continue;
        }
        res = 1E20;
        compute();
        for(i = 0; i < n; ++i)
            swap(p[i].x, p[i].y);
        compute();
        printf("%.3lf\n", res);
    }
}
