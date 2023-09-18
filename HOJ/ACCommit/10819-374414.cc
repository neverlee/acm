#include<cstdio>
#include<cmath>
const double PI=3.14159265354, esp=1.0E-10;
const double END=PI/4;
const double Fen=END/720;
double a,b,x,y,tx,ty;bool can;
int main(){
    while(scanf("%lf%lf%lf%lf",&a,&b,&x,&y)){
        if(a<esp)return 0;
        can=0;
        for(double ag=0.0;ag<=END;ag+=Fen){
            tx=sin(ag)*x+cos(ag)*y;
            ty=cos(ag)*x+sin(ag)*y;
            if((tx<a&&ty<b)||(ty<a&&tx<b)){
                can=1;break;
            }
        }
        if(can)printf("Escape is possible.\n");
        else printf("Box cannot be dropped.\n");
    }
}