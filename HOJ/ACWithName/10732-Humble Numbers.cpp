#include "stdafx.h"
#include <iostream>
using namespace std;

long long renum[6000]={0 ,1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
long long basic[4]={2,3,5,7};
void SetNum()
{
	long long min,t;
	for(long i=11;i<5843;i++)
	{
		min=200000001;
		for(int j=0;j<4;j++)
		{
			for(int k=1;k<i;k++)
			{
				t=renum[k]*basic[j];
				if(t>renum[i-1]&&t<min)min=t;
			}
		}
		renum[i]=min;
	}
}

int main()
{
	long num;
	SetNum();
	while(cin >>num)
	{
		if(!num)return 0;
		cout <<"The " <<num;
		if(num%10==1&&num%100!=11)
			cout <<"st";
		else if(num%10==2&&num%100!=12)
			cout <<"nd";
		else if(num%10==3&&num%100!=13)
			cout <<"rd";
		else
			cout <<"th";
		cout <<" humble number is " <<renum[num] <<"." <<endl;
	}
}