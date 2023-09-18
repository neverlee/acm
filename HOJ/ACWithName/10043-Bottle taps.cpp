//10043-Bottle taps.cpp
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE=2100000;
struct Taps{
	int have;short price;
	Taps(int h, short p){have=h;price=p;}
};
short total;
vector<Taps> vtaps;
int len;short dps[SIZE];
struct CInit{
	short single[22], need[22];//单个价格，需要的那些
	short group[110][22], shop;//商店个数及商店情况
	int trans[22];//转换器
	CInit(){//输入所有数据
		single[0]=total;
		for(short i=1;i<=total;++i)scanf("%d", single+i);//输入单个瓶盖
		short have, i, j;
		scanf("%d",&shop);//商店个数
		for(i=0;i<shop;++i){
			scanf("%d",group[i]);
			scanf("%d",&have);
			for(j=1;j<=have;++j){
				scanf("%d",group[i]+j);
			}
			group[i][j]=0;//设置结束符
		}
		scanf("%d",&need[0]);
		for(short i=1;i<=need[0];++i)scanf("%d",need+i);
		sort(need+1, need+1+need[0]);//对此进行排序
	}
	void DealTrans(){//处理转换器
		trans[0]=0;
		int digi=1;
		for(short t=1,n=1;t<=total;++t){
			if(n<=need[0]&&t==need[n]){//如果没到最后，而且，连到了一个
				trans[t]=digi;
				digi<<=1;
				++n;
			}else{//否则为零
				trans[t]=0;
			}
		}
		int dpl=1<<need[0];//初始化动态规划数组
		dps[0]=0;
		for(int i=1;i<dpl;++i)dps[i]=30000;
	}
	void GetTrans(){
		vtaps.clear();
		vtaps.reserve(20+shop);
		for(int i=1;i<=single[0];++i){//加个单个瓶盖的价格及参数
			if(trans[i])vtaps.push_back(Taps(trans[i], single[i]));
		}
		int thave;short on;
		for(short i=0;i<shop;++i){
			thave=0;
			for(short j=1;group[i][j]!=0;++j){//
				on=group[i][j];
				thave|=trans[on];
			}
			if(thave)vtaps.push_back(Taps(thave,group[i][0]));
		}
	}
};
inline int Min(int a,int b){return a<b?a:b;}
void DoDp(){
	len=0;int next, thave, tprice;
	for(int i=0;i<vtaps.size();++i){
		thave=vtaps[i].have;
		tprice=vtaps[i].price;
		for(int j=len;j>=0;--j){
			next=j|thave;
			dps[next]=Min(dps[next], dps[j]+tprice);
			len=len>next?len:next;
		}
	}
	printf("%ld\n",dps[len]);
}
int main(){
	while((scanf("%d",&total)!=EOF)&&total){
		CInit *cinit=new CInit;
		cinit->DealTrans();
		cinit->GetTrans();
		delete cinit;
		DoDp();
	}
	return 0;
}
