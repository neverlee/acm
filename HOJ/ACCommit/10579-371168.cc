#include<cstdio>
#include<cmath>
class Prime{
protected:
    bool *is;
    int len;
public:
    Prime(int l){
        len=l;
        is = new bool[len];
        for(int i=3;i<len;i+=2){
            is[i]=1;
        }
        is[0]=is[1]=0;is[2]=1;
        int k,end=(int)sqrt((double)len);;
        for(int i=3;i<=end;i+=2)
            if(is[i])
                for(int j=i;(k=i*j)<=l;j+=2)
                    is[k]=0;
    }
    bool isPrime(int num){
        if(num<0||num>=len)return false;
        if(num==2)return true;
        if(num%2==0)return false;
        return is[num];
    }
    ~Prime(){
        delete[] is;
    }
};
int main(){
    int num,tmp;bool done;
    Prime prime(1000000);
    while(scanf("%ld",&num)){
        if(num==0)return 0;
        printf("%7ld ", num);
        done=0;
        do{
            if(prime.isPrime(num)){
                printf("%7ld\n", num);
                done=1;
                break;
            }
            tmp=0;
            while(num>0){
                tmp+=num%10;num/=10;
            }
            num=tmp;
        }while(num>9);
        if(done==0){
            if(prime.isPrime(num)){
                printf("%7ld\n", num);
            }else{
                printf("   none\n");
            }
        }
    }
}