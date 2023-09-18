#include <cstdio>

int m, s, r;

int maxnine;
int minabs;
int mindata;

int get_nine(int m, int s) {
    return (m>=90) + (m%10==9) + (s>=90) + (s%10==9);
}

int iabs(int i) {
    return i>=0?i:-i;
}

void check(int i, int im, int is) {
    int hn = get_nine(im, is);
    int abs = iabs(r-i);
    int d = ((im<<8)|is);
    if (hn<maxnine) {
        return;
    } else if (hn==maxnine) {
        if (abs>minabs) {
            return;
        } else if (abs==minabs) {
            if (d>mindata) {
                return;
            }
        }
    }
    maxnine = hn;
    minabs = abs;
    mindata = d;
}

int main() {
    while (scanf("%d:%d", &m, &s), m||s) {
        r = m*60 + s;
        int d = (r-1)/10;
        int start = r-d>0?r-d:0;
        int end = r+d<61*99?r+d:61*99;
        maxnine = 0;
        minabs = 0xffff;
        mindata = 0xffff;
        for (int i=start; i<=end; ++i) {
            int im, is;
            im = i/60; is = i%60;
            check(i, im, is);
            if (im>0&&is<40) {
                im -= 1;
                is += 60;
                check(i, im, is);
            }
        }
        printf("%02d:%02d\n", mindata>>8, mindata&0xff);
    }
}