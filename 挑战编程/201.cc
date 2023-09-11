#include <iostream>

using namespace std;
long num[3000];
short in;

inline long absd(long num)
{return num<0?-num:num;}

int main()
{
	s1:while(cin >>in)
	{
		for(int i=0;i<in;i++)
			cin >>num[i];
		bool ishave[3001]={0};
		for(int i=1;i<in;i++)
		{
			short t=absd(num[i]-num[i-1]);
			if(t<in)
				ishave[t]=1;
			else
			{
				cout <<"Not jolly" <<endl;
				goto s1;
			}
		}
		for(int i=1;i<in;i++)
			if(!ishave[i])
			{
				cout <<"Not jolly" <<endl;
				goto s1;
			}
		cout <<"Jolly" <<endl;
	}
	return 0;
}