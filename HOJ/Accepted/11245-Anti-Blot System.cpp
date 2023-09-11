//11245-Anti-Blot System.cpp
#include<cstdio>
#include<cstring>
char str[1000], tmp[100];
int a,b;
int main(){
	int t; scanf("%d%*c", &t);
	while(t--) {
		gets(str);
		gets(str);
		if(sscanf(str, "%ld + %ld = %s", &a, &b, tmp)==3)
			printf("%ld + %ld = %ld\n",a,b,a+b);
		else if(sscanf(str, "%ld + %s = %ld", &a, tmp, &b)==3)
			printf("%ld + %ld = %ld\n",a,b-a,b);
		else if(sscanf(str, "%s + %ld = %ld", tmp, &a, &b)==3)
			printf("%ld + %ld = %ld\n",b-a,a,b);
	}
}
