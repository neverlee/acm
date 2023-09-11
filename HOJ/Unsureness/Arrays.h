#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
class Element{
public:
	int val,r,c;
	Element(int v, int ar, int ac){
		val=v;r=ar;c=ac;
	}
	int Compare(Element &e){
		if(r<e.r)return -1;
		if(r==e.r&&c<e.c)return -1;
		if(r==e.r&&c==e.c)return 0;
		return 1;
	}
	bool operator<(Element &e){
		return Compare(e)<0;
	}
	bool operator==(Element &e){
		return Compare(e)==0;
	}
};

class Matrix{
public:
	int row, column;
	vector<Element> eles;
	Matrix(int r, int c){row=r;column=c;}
	void Sort(){
		sort(eles.begin(), eles.end());
	}
	Matrix operator+(Matrix &m){
		Matrix result(m.row, m.column);
		int i,j,tmp;
		for(i=0,j=0;i<eles.size()&&j<m.eles.size();){
			tmp=eles[i].Compare(m.eles[j]);
			if(tmp<0)result.eles.push_back(eles[i++]);
			else result.eles.push_back(eles[j++]);
		}
		for(;i<eles.size();++i){
			result.eles.push_back(eles[i]);
		}
		for(;j<m.eles.size();++j){
			result.eles.push_back(m.eles[j]);
		}
	}
	void Display(){
		for(int i=0;i<eles.size();++i){
			printf("(%ld,%ld) value: %ld\n", eles[i].r, eles[i].c, eles[i].val);
		}
	}
};
int main(){
	Matrix a(3,4), b(3,4), c(3,4);
	int num;
	printf("Please input the number of elements:");
	scanf("%ld",&num);
	printf("Please input the row, the column and value:");
	for(int i=0;i<num;++i){
		scanf("%ld %ld:%ld", &a.eles[i].r, &a.eles[i].c, &a.eles[i].val);
	}
	a.Sort();
	printf("Please input the number of elements:");
	scanf("%ld",&num);
	printf("Please input the row, the column and value:");
	for(int i=0;i<num;++i){
		scanf("%ld %ld:%ld", &b.eles[i].r, &b.eles[i].c, &b.eles[i].val);
	}
	b.Sort();
	c=a+b;
	c.Display();
	return 0;
}