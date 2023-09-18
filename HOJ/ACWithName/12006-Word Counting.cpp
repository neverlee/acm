//12006-Word Counting.cpp
#include<cstdio>
#include<cstring>
#include<ctype.h>
char str[10000];
int total;
int Count(){
	int have=0, n;
	for(int i=0;str[i];){
		if(isdigit(str[i])||isalpha(str[i])){
			for(n=i+1;isdigit(str[n])||isalpha(str[n]);++n);
			i=n;++have;
		}else if(isspace(str[i])){
			++i;
		}else{++have;++i;}
	}
	return have;
}
int main(){
	total=0;
	while(gets(str)){
		if(str[0]=='#'){
			printf("%ld\n", total);
			total=0;
			continue;
		}
		total+=Count();
	}
}
