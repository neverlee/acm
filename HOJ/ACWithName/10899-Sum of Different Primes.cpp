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
int rect[14][Size]={0},tmp;
void Init(){
	for(int i=0;cloud[i]<Size;++i){
		for(int j=13;j>0;j--){
			for(int k=rect[j-1][0];k>1;--k){
				tmp=cloud[i]+k;
				if(tmp<Size&&rect[j-1][k]>0){
					rect[j][tmp]+=rect[j-1][k];
					rect[j][0]=tmp>rect[j][0]?tmp:rect[j][0];
				}
			}
		}
		rect[0][cloud[i]]=1;rect[0][0]=cloud[i];
	}
}
int main(){
	int m,k;
	Init();
	while(scanf("%d%d",&m,&k),m||k){
		printf("%d\n",rect[k-1][m]);
	}
	return 0;
}