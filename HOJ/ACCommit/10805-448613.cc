#include <cstdio>
#include <cstring>

int fbl[40] = {1, 2};
const int SIZE = 1000010;
char fbs[SIZE] = "ab";
char ck[SIZE];
int main() {
    for (int i=2; i<40; ++i) {
        fbl[i] = fbl[i-1] + fbl[i-2];
        if (fbl[i] > 1000000) {
            break;
        } else {
            strncpy(fbs+fbl[i-1], fbs, fbl[i-2]);
        }
    }
    while(gets(ck)) {
        if (\'0\' == ck[0]) {
            break;
        }
        bool flag = 1;
        int l = strlen(ck);
        
        for (int i=0; l!=fbl[i]; ++i) {
            if (fbl[i] == 0) {
                flag = 0;
                break;
            }
        }
        
        if (l==1) {
            if (ck[0]!=\'a\' && ck[0]!=\'b\') {
                flag = 0;
            }
        } else if (flag) {
            if (strncmp(ck, fbs, l)) {
                flag = 0;
            }
        }
        
        puts(flag?"true":"false");
    }
}