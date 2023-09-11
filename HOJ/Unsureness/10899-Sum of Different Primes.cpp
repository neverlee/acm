//10899-Sum of Different Primes.cpp
#include<cstdio>
#include<cmath>
class CPrime{
protected:
	int*val;
	int len;
	bool IsPrime(int num){
		int sqn=(int)sqrt((double)num);
		for(int i=0;sqn>=val[i];++i){
			if(num%val[i]==0)return false;
		}
		return true;
	}
public:
	CPrime(int l){
		len=l;
		val=new int[len];
		val[0]=2;val[1]=3;
		for(int i=5,pos=2;pos<len;i+=2){
			if(IsPrime(i)){
				val[pos++]=i;
			}
		}
	}
	int Max(){return val[len-1];}
	int Size(){return len;}
	int operator[](int i){return val[i];}
	~CPrime(){delete[] val;}
};
const int Size = 1121;
CPrime cloud(190);
int rect[14][Size]={0};
void Init(){
	for(int i=0;cloud[i]<1121;++i)rect[0][cloud[i]]=1;
	for(int i=1;i<14;++i){
		
	}
}
int main(){
	printf("%d\n",cloud.Max());
}