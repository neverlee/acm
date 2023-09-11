#include<cstdio>
int num;
double mny[1010],avg,get,give;
int main(){
	char tmp[100];
	while(scanf("%ld",&num)){
		if(num==0)return 0;
		avg=give=get=0;
		for(int i=0;i<num;++i){
			scanf("%lf",&mny[i]);
			avg+=mny[i];
		}
		avg/=num;
        sprintf(tmp, "%.2lf",avg);
        sscanf(tmp, "%lf",&avg);
		for(int i=0;i<num;++i){
			if(mny[i]<avg){
				give+=(avg-mny[i]);
			}else{
				get+=(mny[i]-avg);
			}
		}
		avg=give>get?get:give;
		printf("$%.2lf\n", avg);
	}
}