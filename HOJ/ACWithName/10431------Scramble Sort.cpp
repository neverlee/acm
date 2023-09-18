//10431------Scramble Sort.cpp
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char sep[]=",. ", str[1000];
class PString{
public:
	char *ps;
	PString(char *p){ps=p;}
	bool operator<(const PString &pst)const{
		int i;char a,b;
		for(i=0;*(ps+i)&&*(pst.ps+i);++i){
			a=*(ps+i);b=*(pst.ps+i);
			if(a>='a')a-=32;
			if(b>='a')b-=32;
			if(a<b)return true;
			if(a>b)return false;
		}
		return *(ps+i)<*(pst.ps+i);
	}
};
int main(){
	while(gets(str),str[0]!='.'){
		vector<int> num;
		vector<PString> string;
		vector<char> type;
		int count=0,temp;
		for(char *p=strtok(str,sep); p; p=strtok(NULL,sep)){
			if(isalpha(p[0])){
				type.push_back(1);
				string.push_back(PString(p));
			}else{
				type.push_back(0);
				sscanf(p, "%ld",&temp);
				num.push_back(temp);
			}
		}
		sort(string.begin(),string.end());
		sort(num.begin(),num.end());
		int si=0,ni=0;
		for(int i=0;i<type.size();++i){
			if(i!=0)printf(", ");
			if(type[i]){
				printf("%s", string[si++].ps);
			}else{
				printf("%ld", num[ni++]);
			}
		}
		printf(".\n");
	}
	return 0;
}