// 10399-Appointment.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <cstdio>

int main()
{
	int ncase;
	scanf("%ld",&ncase);
	double time=60.0;
	int x,y;double z;
	for(int text=0;text<ncase;text++)
	{
		scanf("%ld%ld%lf",&x,&y,&z);
		if(x>y)y+=12;
		time*=(y-x);
		if(z>=time)
			printf("1.0000000\n");
		else
		{
			printf("%.7lf\n",(2.0*time*z-z*z)/(time*time));
		}
	}
	return 0;
}