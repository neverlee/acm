#include<cmath>
#include<cstdio>
const int SIZE=3500;
class CPrime{
protected:
    int*val;
    int len;
    bool IsPrime(int num){
        int sqn=(int)sqrt((double)num);
        for(int i=0;sqn>=val[i];++i){
            if(num%val[i]==0)return false;
        }
        return true;
    }
public:
    CPrime(int l){
        len=l;
        val=new int[len];
        val[0]=2;val[1]=3;
        for(int i=5,pos=2;pos<len;i+=2){
            if(IsPrime(i)){
                val[pos++]=i;
            }
        }
    }
    int Max(){return val[len-1];}
    int Size(){return len;}
    int operator[](int i){return val[i];}
    int GetPhi(int num){
        int res=num;
        for(int i=0;i<SIZE&&num>=(*this)[i];++i){
            if(num%(*this)[i]==0){
                do{
                    num/=(*this)[i];
                }while(num%(*this)[i]==0);
                res=res/(*this)[i]*((*this)[i]-1);
            }
        }
        if(num>1)res=res/num*(num-1);
        return res;
    }
    ~CPrime(){
        delete[] val;
    }
};
CPrime cloud(SIZE);

class XMod{
protected:
    int num,mod;
public:
    XMod(int n, int m){num=n%m;mod=m;}
    long long Get(int xd){
        if(xd==1)return num;
        long long div;
        div=Get(xd/2);
        div=div*div%mod;
        if(xd%2){
            return div*num%mod;
        }
        return div;
    }
};

class NewNumber{
protected:
    int val[101], len, mod;;
    CPrime &cloud;
    int Calu(int md, int pos=0){
        int phim=cloud.GetPhi(md);
        if(pos==len){
            return val[len]%md;
        }
        int atp=Calu(phim,pos+1)+phim;
        XMod xmd(val[pos], md);
        return (int)xmd.Get(atp);
    }
public:
    NewNumber(CPrime&c):cloud(c){
        scanf("%ld%ld%ld",val+0,&len,&mod);
        for(int i=1;i<=len;++i)scanf("%ld",val+i);
    }
    int GetResult(){
        return Calu(mod);
    }
};
int main(){
    int ncase;scanf("%ld",&ncase);
    while(ncase--){
        NewNumber nNb(cloud);
        printf("%ld\n",nNb.GetResult());
    }
    return 0;
}