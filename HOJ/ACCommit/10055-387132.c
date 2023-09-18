#include<stdio.h>
#define ESP 1e-7
typedef struct{
    double need, price;
}Station;
double distance, capacity, unit;
Station stat[100];
int num;
void Input(){
    int i;
    scanf("%lf%lf%lf%lf",&distance, &capacity, &unit, &stat[0].price);
    stat[0].need=0;
    scanf("%ld",&num);
    for(i=1;i<=num;++i){
        scanf("%lf%lf",&stat[i].need,&stat[i].price);
        stat[i].need/=unit;
    }
    stat[num+1].need=distance/unit;
    stat[num+1].price=0;
}
void Deal(){
    int i,j,best=0;
    double remain=0, all=0;
    for(i=0;i<=num;){
        if(capacity<stat[i+1].need-stat[i].need){
            printf("No solution");
            return;
        }
        best=i+1;
        for(j=i+1;j<=num+1&&capacity>stat[j].need-stat[i].need;++j){
            if(stat[i].price>=stat[j].price){
                if(remain>=stat[j].need-stat[i].need){
                    remain-=(stat[j].need-stat[i].need);
                }else{
                    all+=stat[i].price*(stat[j].need-stat[i].need-remain);
                    remain=0;
                }
                i=j;
                break;
            }
            best=stat[j].price<stat[best].price?j:best;
        }
        if(best>i){
            all+=stat[i].price*(capacity-remain);
            remain=capacity-(stat[best].need-stat[i].need);
            i=best;
        }
    }
    printf("%.2lf\n",all);
}
int main(){
    Input();
    Deal();
    return 0;
}