//10160-Quantum Mechanical States.cpp
#include<cstdio>
int main()
{
	double pe,p,m;
	while(scanf("%lf%lf%lf",&pe,&p,&m)!=EOF)
	{
		if(pe<p&&pe<m)printf("bound\n");
		else printf("scattering\n");
	}
	return 0;
}