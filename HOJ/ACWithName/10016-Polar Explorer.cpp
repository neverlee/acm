//10016-Polar Explorer.cpp
#include<cstdio>
const double PI=3.1415927;
int main(){
	char str[100];
	int radius, gallons, angle;
	double dist;
	while(gets(str),str[0]=='S'){
		scanf("%ld%ld%ld", &radius, &gallons, &angle);
		if(angle>180)angle=360-angle;
		dist=radius*angle*PI/180.0;
		gallons*=5;
		if((dist*=2)<=gallons){
			printf("YES %ld\n",(int)((gallons-dist)/5));
		}else{
			printf("NO %ld\n",(int)gallons);
		}
	}
	return 0;
}