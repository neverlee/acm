#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int ncase, len, dist;
const double esp=1E-7;
double dist2;
struct Itv{
    double xs,xe;
    void Set(int x,int y){
        if(y==dist){
            xs=xe=x;
            return;
        }
        double tmp=sqrt(dist2-y*y);
        xs=x-tmp;xe=x+tmp;
    }
};
Itv itv[1010];
struct PItv{
    Itv*pv;
    void Set(Itv*p){pv=p;};
    bool operator<(const PItv&pi)const{
        return (pv->xe)<(pi.pv->xe);
    }
}pitv[1010];

bool Init(){
    dist2=dist*dist;
    int tx,ty;bool error=0;
    for(int i=0;i<len;++i){
        scanf("%ld%ld", &tx, &ty);
        if(ty>dist||error){error=1;continue;}
        itv[i].Set(tx,ty);
        pitv[i].Set(itv+i);
    }
    printf("Case %ld: ", ncase);
    if(error){
        printf("-1\n");
        return false;
    }
    sort(pitv, pitv+len);
    return true;
}
int Result(){
    int count=1;
    double sp=pitv[0].pv->xe;
    for(int i=1;i<len;++i){
        if(!(pitv[i].pv->xs<=sp&&pitv[i].pv->xe>=sp)){
            ++count;sp=pitv[i].pv->xe;
        }
    }
    return count;
}
int main(){
    for(ncase=1;scanf("%ld%ld", &len, &dist), len; ++ncase){
        if(Init()){
            printf("%ld\n",Result());
        }
    }
    return 0;
}