#include <stdio.h>
#include <string.h>
int main() {
    bool flag[10101]={0};
    int i, tmp, result;
    for(i = 1; i < 10001; i++)
    {
        tmp = result = i;
        while(tmp > 0) {
            result += tmp % 10;
            tmp /= 10;
        }
        flag[result] = 1;
    }

    for(i = 1; i < 10001; i++)
    {
        if(flag[i] != 1)
        {
            printf("%d\n", i);
        }
    }
}