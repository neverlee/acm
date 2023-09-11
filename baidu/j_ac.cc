#include <stdio.h>

int main()
{
	int n,m,min=1000000000,x,a,b,count;

	scanf("%d%d",&n,&m);
	while (m --)
	{
		scanf("%d%d",&a,&b);

		count = (b*n)/(a+b) + 1;
		x = a * count - b * (n - count);
		if (x < min)
			min = x;
	}
	printf("%d\n",min);

	return 0;
}
