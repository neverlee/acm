//10142-Postfix expression evaluation.cpp
#include<cstdio>
#include<stack>
using namespace std;
char str[100];
int tmp;
stack<int> calu;
int main(){
	while(gets(str)){
		int i=0;
		while(str[i]){
			if(str[i]>='0'&&str[i]<='9'){
				tmp=str[i++]-'0';
				while(str[i]>='0'&&str[i]<='9'){
					tmp=tmp*10+str[i]-'0';++i;
				}
				calu.push(tmp);
			}
			if(str[i]=='+'){
				tmp=calu.top();calu.pop();
				calu.top()+=tmp;
			}
			if(str[i]=='-'){
				tmp=calu.top();calu.pop();
				calu.top()-=tmp;
			}
			if(str[i]=='*'){
				tmp=calu.top();calu.pop();
				calu.top()*=tmp;
			}
			++i;
		}
		printf("%ld\n",calu.top());
		calu.pop();
	}
	return 0;
}