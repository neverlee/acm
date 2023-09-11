//10286-A Simple High-Precision Problem.cpp
#include<cstdio>
#include<cstring>
typedef unsigned uint;
char str[100];uint au;
class BitNumber{
protected:
	char bits[400];int median;
public:
	BitNumber(){median=0;}
	void Input(){
		char str[100], dig[]={1,2,4,8};
		scanf("%s %x",str,&au);
		int len=strlen(str);
		for(int i=len-1;i>=0;--i){
			if(str[i]==',')continue;
			if(str[i]<='9')str[i]-='0';
			else str[i]-=('a'-10);
			for(int j=0;j<4;++j){
				bits[median++]=(str[i]&dig[j])>0;
			}
		}
	}
	void Add(){
		int have=0;
		for(int i=0;i<au;++i){have+=bits[i];bits[i]=0;}
		if(median<=au){
			bits[au]=1;
			median=au+1;
		}else{
			if(have==0)return;
			++bits[au];
			bits[median]=0;
			for(int i=au;i<median;++i){
				if(bits[i]>1){
					bits[i]=0;
					++bits[i+1];
					if(i+1==median)++median;
				}
			}
		}
	}
	void Display(){
		while(median%4){
			bits[median++]=0;
		}
		char tmp;
		for(int i=median-1;i>=0;i-=4){
			tmp=(bits[i]<<3)|(bits[i-1]<<2)|(bits[i-2]<<1)|bits[i-3];
			if(tmp<10)tmp+='0';
			else tmp+=('a'-10);
			putchar(tmp);
		}
		putchar('\n');
	}
};
int main(){
	int ncase;scanf("%ld",&ncase);
	while(ncase--){
		BitNumber bitn;
		bitn.Input();
		bitn.Add();
		bitn.Display();
	}
	return 0;
}
