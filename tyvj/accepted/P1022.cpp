#include <cstdio>
#include <cstring>
int main() {
	__int64 sn, tn;
	scanf("%I64d", &sn);
	if(sn==0) {
		putchar('0');
		return 0;
	}
	int flag=sn<0;
	sn=sn>0?sn:-sn;
	char str[100];
	memset(str,'0',sizeof(str));
	str[99]=0;
	int pi;
	for(tn=1,pi=98; sn!=0; tn<<=1, --pi)
	if((sn&tn)>0) {
		if((pi%2==flag&&str[pi]=='0')||(pi%2!=flag&&str[pi]=='1')) sn-=tn;
		else sn+=tn;
		str[pi]='1'+'0'-str[pi];
	}
	while(str[pi]=='0') ++pi;
	puts(str+pi);
}
