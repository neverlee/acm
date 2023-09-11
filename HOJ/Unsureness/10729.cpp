#include<cmath>
#include<cstdio>

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
	int Max(){
		return val[len-1];
	}
	int Size(){
		return len;
	}
	int operator[](int i){
		return val[i];
	}
	~CPrime(){
		delete[] val;
	}
};
const int SIZE=2000
CPrime mylove(SIZE);
int num;
int GetPhi(){
	int res=num;
	for(int i=0;i<SIZE&&num>=mylove[i];++i){
		if(num%mylove[i]==0){
			do{
				num/=mylove[i];
			}while(num%mylove[i]==0);
			res=res/mylove[i]*(mylove[i]-1);
		}
	}
	if(num>1)res=res/num*(num-1);
	return res;
}
int main(){
	while(scanf("%ld",&num),num>0){
		printf("%ld\n",GetPhi());
	}
	return 0;
}