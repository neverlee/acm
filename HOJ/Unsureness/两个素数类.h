//自己封装的两个素数类

#include<cmath>

class SPrime{
protected:
	bool *is;
	int len;
public:
	SPrime(int l){
		len=l;
		int div=len/2;
		is = new bool[div];
		for(int i=0;i<div;++i){
			is[i]=1;
		}
		is[0]=0;is[1]=1;
		int k,end=(int)sqrt((double)len);;
		for(int i=3;i<=end;i+=2)
			if(is[i])
				for(int j=i;(k=i*j)<=l;j+=2)
					is[k/2]=0;
	}
	char isPrime(int num){
		if(num<2||num>=len)return -1;
		if(num==2)return true;
		if(num%2==0)return false;
		return is[num/2];
	}
	int Max(){
		return len;
	}
	~SPrime(){
		delete[] is;
	}
	friend class Iterator;
	class Iterator{
	protected:
		int have,max,point,recent;
		SPrime&sprime;
	public:
		Iterator(SPrime &sp):sprime(sp){
			have=max=1;point=recent=0;
			for(int i=1;i<sp.len/2;++i){
				if(sp.is[i]){
					++have;max=2*i+1;
				}
			}
		}
		int Size(){
			return Size();
		}
		int Max(){
			return max;
		}
		int Remain(){
			return have-recent;
		}
		int Next(int num=1){
			if(point){
				for(int i=0;i<num;){
					if(sprime.is[point++]){
						++recent;
						++i;
					}
				}
				return (point)*2-1;
			}else{
				point=1;
				recent=1;
				return 2;
			}
		}
	};
};

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
	int Find(int num){
		int low=0, high=len-1, mid;
		if(num==val[low])return low;
		while(low<=high){
			mid=low+(high-low)/2;//使用 (low + high) / 2 会有整数溢出的问题
			if(val[mid]==num)return mid;
			if(val[mid]>num)high=mid-1;
			else low=mid+1;
		}
		return -1;
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
