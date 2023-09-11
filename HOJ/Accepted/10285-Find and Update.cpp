//10285-Find and Update.cpp
#include <iostream>
#include <map>
using namespace std;
int main(){
	typedef map<int, char> maptype;
	maptype m;
	char s[30],a;int t, n;
	scanf("%d", &t);
	while(t--){
		while(true){
			scanf("%s", s);
			if(s[0] == 'S')break;
			if('U' == s[0]){
				scanf("%d %c", &n, &a);
				m[n] = a;
			}else{
				scanf("%d", &n);
				if(m.find(n)==m.end())printf("A");
				else printf("%c", m[n]);
			}
		}
		printf("\n");
		m.clear();
	}
	return 0;
}