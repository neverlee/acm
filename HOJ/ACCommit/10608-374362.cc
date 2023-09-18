#include<cstdio>

typedef unsigned long long ull;
const ull DIVI= 1000000000000000000ULL;
const ull MAX =  100000000000000000ULL;
const ull GETLAST = 100000000000000ULL;
const ull INWEI =    50000000000000ULL;
int num,ncase,i;
class TwoNum{
public:
    ull value;
    short exp;
    void SetNum(ull v,short e){value=v;exp=e;}
    ull GetValue(){return value;}
    void Print();
}result[9010];

void TwoNum::Print()
{printf("%I64u.%03I64uE-%d\n",value/1000,value%1000,exp);}

void InitResult()
{
    ull tv;short te;bool isBig;
    result[0].SetNum(MAX,0);
    for(i=1;i<9010;i++)
    {
        tv=result[i-1].value*5ULL;
        isBig=tv<DIVI;
        te=result[i-1].exp+isBig;
        if(!isBig)tv/=10;
        result[i].SetNum(tv,te);
    }
    for(i=1;i<9010;++i){
        if((result[i].value%GETLAST)>=INWEI)
            result[i].value+=GETLAST;
        result[i].value/=GETLAST;
    }
}

int main(){
    InitResult();
    scanf("%ld",&ncase);
    while(ncase--)
    {
        scanf("%ld",&num);
        printf("2^-%ld = ",num);
        result[num].Print();
    }
    return 0;
}
