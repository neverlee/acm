#include<cstdio>

const int MOD = 10007;
const int SIZE = 10000;

int count, num[17][SIZE], len[17], level;

void Init(){
    for(int i=0;i<count;++i){
        scanf("%ld", &num[0][i]);
    }
    len[0]=1;
    int i,lv;
    for(i=1,lv=1;(lv<<1)<=count;++i,lv*=2){
        len[i]=lv<<1;
        for(int j=0;j+lv+lv<=count;++j){
            num[i][j]=(num[i-1][j]*num[i-1][j+lv])%MOD;
        }
    }
    level=i;
}


void Work(){
    int times, from, to, result;
    scanf("%ld", ×);
    while(times--){
        scanf("%ld%ld", &from, &to);
        --from;
        result=1;
        for(int i=level-1;i>=0;--i){
            if(to-from>=len[i]){
                result = (result*num[i][from])%MOD;
                from+=len[i];
            }
        }
        printf("%ld",result);
    }
    printf("\n");
}


int main(){
    while(scanf("%ld",&count)){
        if(count==0)return 0;
        Init();
        Work();
    }
}