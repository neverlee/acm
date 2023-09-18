#include <stdio.h>
#include <math.h>

int main() {
    double r, a, b, c, t;
    scanf("%lf%lf%lf%lf", &r, &a, &b, &c);
    t = (sqrt(r*a)/(r-a)+sqrt(r*b)/(r-b)+sqrt(r*c)/(r-c));
    printf("%.2lf", 2*r*r*t);
    return 0;
}
