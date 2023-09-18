// 10376-Questions and answers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
short num[5010];
int en,an,k;
int main()
{
	vector<int> num(5001,0);
	vector<int>::iterator iter=num.begin();
	scanf("%ld",&en);
	for(int i=0;i<en;i++){scanf("%ld",&k);++num[k];}
	for(int i=1;i<=5000;i++)num[i]+=num[i-1];
	getchar();
	scanf("###");
	scanf("%ld",&an);
	while(an--)
	{
		scanf("%ld",&en);
		iter=lower_bound(num.begin(),num.end(),en);
		printf("%ld\n",iter-num.begin());
	}
	return 0;
}