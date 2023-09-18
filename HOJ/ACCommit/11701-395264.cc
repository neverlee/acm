#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int style[6][3]={
    0,1,2,
    0,2,1,
    1,0,2,
    1,2,0,
    2,0,1,
    2,1,0
};
int permul[24][4]={0,1,2,3};
int num[4];
double BaseCalu(double a, double b, int op){
    switch(op){
    case 0:return a+b;
    case 1:return a-b;
    case 2:return a*b;
    case 3:
        if(b==0)return -1000000000;
        return a/b;
    }
}
double Calu(int opc, int sy){
    int i,j,rs,op[4];
    double itmp[4],tmp;
    for(i=0;i<4;++i){
        itmp[i]=num[i];
        op[i]=(opc>>(4-(i<<1)))&3;
    }
    for(i=0;i<3;++i){
        rs=style[sy][i];
        tmp=BaseCalu(itmp[rs],itmp[rs+1],op[rs]);
        if(tmp==-1000000000)return -1000000000;
        itmp[rs]=itmp[rs+1]=tmp;
        if((sy==2||sy==3)&&i==1)
            itmp[1]=itmp[2]=tmp;
    }
    return itmp[rs];
}

char Find(){
    int opc,sy;
    double result;
    do{
        for(opc=0;opc<64;++opc){
            for(sy=0;sy<6;++sy){
                result=Calu(opc,sy);
                if(fabs(result-24)<1E-7)return 1;
            }
        }
    }while(next_permutation(num, num+4));
    return 0;
}
int ParseInt(char *&p){
    switch(*p){
    case \'1\':p+=3;return 10;
    case \'A\':p+=2;return 1;
    case \'J\':p+=2;return 11;
    case \'Q\':p+=2;return 12;
    case \'K\':p+=2;return 13;
    }
    p+=2;return *(p-2)-\'0\';
}
char Input(){
    char str[100], *p=str;
    if(!gets(str))return 0;
    for(int i=0;i<4;++i){
        num[i]=ParseInt(p);
    }
    sort(num, num+4);
    return 1;
}
int main(){
    while(Input()){
        if(Find())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
