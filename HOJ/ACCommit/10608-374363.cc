#include<cstdio>

typedef unsigned __int64 ull;
const ull DIVI= 1000000000000000000ULL;
const ull MAX =  100000000000000000ULL;
const ull GETLAST = 100000000000000ULL;
const ull INWEI =    50000000000000ULL;
int num,ncase,i;
struct TwoNum{
    short val;
    short exp;
    void Print(){printf("%d.%03dE-%d\n",val/1000,val%1000,exp);}
}res[9001];

void Initres(){
    ull tv=MAX;short te=0;bool isBig;
    res[0].exp=0;
    for(i=1;i<9010;i++){
        tv*=5ULL;
        isBig=tv<DIVI;
        te=res[i-1].exp+isBig;
        if(!isBig)tv/=10;
        res[i].val=(short)(tv/GETLAST);
        if((tv%GETLAST)>=INWEI)res[i].val+=1;
        res[i].exp=te;
    }
}

int main(){
    Initres();
    scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%ld",&num);
        printf("2^-%ld = ",num);
        res[num].Print();
    }
    return 0;
}
