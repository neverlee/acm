#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE=2100000;
struct Taps{
    int have;short price;
    Taps(int h, short p){have=h;price=p;}
};
short total;
vector<Taps> vtaps;
int len;short dps[SIZE];
struct CInit{
    short single[22], need[22];//\xb5\xa5\xb8\xf6\xbc\xdb\xb8\xf1\xa3\xac\xd0\xe8\xd2\xaa\xb5\xc4\xc4\xc7\xd0\xa9
    short group[110][22], shop;//\xc9\xcc\xb5\xea\xb8\xf6\xca\xfd\xbc\xb0\xc9\xcc\xb5\xea\xc7\xe9\xbf\xf6
    int trans[22];//\xd7\xaa\xbb\xbb\xc6\xf7
    CInit(){//\xca\xe4\xc8\xeb\xcb\xf9\xd3\xd0\xca\xfd\xbe\xdd
        single[0]=total;
        for(short i=1;i<=total;++i)scanf("%d", single+i);//\xca\xe4\xc8\xeb\xb5\xa5\xb8\xf6\xc6\xbf\xb8\xc7
        short have, i, j;
        scanf("%d",&shop);//\xc9\xcc\xb5\xea\xb8\xf6\xca\xfd
        for(i=0;i<shop;++i){
            scanf("%d",group[i]);
            scanf("%d",&have);
            for(j=1;j<=have;++j){
                scanf("%d",group[i]+j);
            }
            group[i][j]=0;//\xc9\xe8\xd6\xc3\xbd\xe1\xca\xf8\xb7\xfb
        }
        scanf("%d",&need[0]);
        for(short i=1;i<=need[0];++i)scanf("%d",need+i);
        sort(need+1, need+1+need[0]);//\xb6\xd4\xb4\xcb\xbd\xf8\xd0\xd0\xc5\xc5\xd0\xf2
    }
    void DealTrans(){//\xb4\xa6\xc0\xed\xd7\xaa\xbb\xbb\xc6\xf7
        trans[0]=0;
        int digi=1;
        for(short t=1,n=1;t<=total;++t){
            if(n<=need[0]&&t==need[n]){//\xc8\xe7\xb9\xfb\xc3\xbb\xb5\xbd\xd7\xee\xba\xf3\xa3\xac\xb6\xf8\xc7\xd2\xa3\xac\xc1\xac\xb5\xbd\xc1\xcb\xd2\xbb\xb8\xf6
                trans[t]=digi;
                digi<<=1;
                ++n;
            }else{//\xb7\xf1\xd4\xf2\xce\xaa\xc1\xe3
                trans[t]=0;
            }
        }
        int dpl=1<<need[0];//\xb3\xf5\xca\xbc\xbb\xaf\xb6\xaf\xcc\xac\xb9\xe6\xbb\xae\xca\xfd\xd7\xe9
        dps[0]=0;
        for(int i=1;i<dpl;++i)dps[i]=30000;
    }
    void GetTrans(){
        vtaps.clear();
        vtaps.reserve(20+shop);
        for(int i=1;i<=single[0];++i){//\xbc\xd3\xb8\xf6\xb5\xa5\xb8\xf6\xc6\xbf\xb8\xc7\xb5\xc4\xbc\xdb\xb8\xf1\xbc\xb0\xb2\xce\xca\xfd
            if(trans[i])vtaps.push_back(Taps(trans[i], single[i]));
        }
        int thave;short on;
        for(short i=0;i<shop;++i){
            thave=0;
            for(short j=1;group[i][j]!=0;++j){//
                on=group[i][j];
                thave|=trans[on];
            }
            if(thave)vtaps.push_back(Taps(thave,group[i][0]));
        }
    }
};
inline int Min(int a,int b){return a<b?a:b;}
void DoDp(){
    len=0;int next, thave, tprice;
    for(int i=0;i<vtaps.size();++i){
        thave=vtaps[i].have;
        tprice=vtaps[i].price;
        for(int j=len;j>=0;--j){
            next=j|thave;
            dps[next]=Min(dps[next], dps[j]+tprice);
            len=len>next?len:next;
        }
    }
    printf("%ld\n",dps[len]);
}
int main(){
    while((scanf("%d",&total)!=EOF)&&total){
        CInit *cinit=new CInit;
        cinit->DealTrans();
        cinit->GetTrans();
        delete cinit;
        DoDp();
    }
    return 0;
}