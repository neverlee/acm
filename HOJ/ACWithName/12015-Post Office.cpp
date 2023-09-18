//12015-Post Office.cpp
#include<cstdio>
#include<algorithm>
using namespace std;
double a[3];
int main(){
	while(scanf("%lf%lf%lf",a,a+1,a+2)){
		if(!(a[0]||a[1]||a[2]))return 0;
		sort(a,a+3);
		if(a[0]>=0.25&&a[1]>=90&&a[2]>=125){
			if(a[0]<=7&&a[1]<=155&&a[2]<=290) puts("letter");
			else if(a[0]<=50&&a[1]<=300&&a[2]<=380) puts("packet");
			else if(2*a[0]+2*a[1]+a[2]<=2100) puts("parcel");
			else puts("not mailable");
		}else puts("not mailable");
	}
}
