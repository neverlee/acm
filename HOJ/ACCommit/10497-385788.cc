#include<cstdio>
#include<algorithm>
using namespace std;
struct Gift{
    int x,y,dx,dy;
}gift[100100];
int num;
struct Pdx{
    Gift*ptg;
    bool operator<(const Pdx &np)const {
        return ptg->x<np.ptg->x;
    }
};
struct Pdy{
    Gift*ptg;
    bool operator<(const Pdy &np)const {
        return ptg->y<np.ptg->y;
    }
};
void GetDx(){
    Pdx*pdx=new Pdx[num];
    for(int i=0;i<num;++i)pdx[i].ptg=gift+i;
    sort(pdx, pdx+num);
    pdx[0].ptg->dx=0;
    for(int i=num-1;i>0;--i)
        pdx[0].ptg->dx+=(pdx[i].ptg->x-pdx[0].ptg->x);
    int dx;
    for(int i=1,j=num-1;i<num;++i,--j){
        dx=pdx[i].ptg->x-pdx[i-1].ptg->x;
        pdx[i].ptg->dx=pdx[i-1].ptg->dx+(i-j)*dx;
    }
    delete []pdx;
}
void GetDy(){
    Pdy*pdy=new Pdy[num];
    for(int i=0;i<num;++i)pdy[i].ptg=gift+i;
    sort(pdy, pdy+num);
    pdy[0].ptg->dy=0;
    for(int i=num-1;i>0;--i)
        pdy[0].ptg->dy+=(pdy[i].ptg->y-pdy[0].ptg->y);
    int dy;
    for(int i=1,j=num-1;i<num;++i,--j){
        dy=pdy[i].ptg->y-pdy[i-1].ptg->y;
        pdy[i].ptg->dy=pdy[i-1].ptg->dy+(i-j)*dy;
    }
    delete []pdy;
}
int GetMax(){
    int mm=gift[0].dx+gift[0].dy, tmp;
    for(int i=1;i<num;++i){
        tmp=gift[i].dx+gift[i].dy;
        if(tmp<mm)mm=tmp;
    }
    return mm;
}
int main(){
    scanf("%d",&num);
    for(int i=0;i<num;++i)scanf("%d%d",&gift[i].x,&gift[i].y);
    GetDx();
    GetDy();
    printf("%ld",GetMax());
}