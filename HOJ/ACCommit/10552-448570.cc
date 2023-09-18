#include <cstdio>
#include <cstring>

int main() {
    int amount, luck, cards[20];
    for (int T=1; ~scanf("%d%d", &amount, &luck); ++T) {
        for (int i=0; i<20; ++i) {
            scanf("%d", cards+i);
        }
        bool man[60];
        memset(man, 1, 60);

        int remain = amount;
        bool flag = 1;
        for (int c=0; c<20&&flag; ++c) {
            int count = 0;
            for (int i=1; i<=amount; ++i) {
                if (man[i]) {
                    ++count;

                    if (remain==luck) {
                        flag = 0;
                        break;
                    }
                    
                    if (count==cards[c]) {
                        man[i] = 0;
                        --remain;
                        count = 0;
                    }
                }
            }
        }

        printf("Selection #%d\n", T);
        for (int i=1; i<=amount; ++i) {
            if (man[i]) {
                printf("%d ", i);
            }
        }
        printf("\n\n");
    }
}