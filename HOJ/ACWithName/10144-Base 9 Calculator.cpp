#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int n91,n92,n101,n102;
	while(cin >>n91 >>n92)
	{
		n101=n102=0;
		int k9;
		k9=1;while(n91>0){n101+=((n91%10)*k9);k9*=9;n91/=10;}
		k9=1;while(n92>0){n102+=((n92%10)*k9);k9*=9;n92/=10;}
		n101+=n102;n102=0;
		int k10=1;
		while(n101>0){n102+=((n101%9)*k10);k10*=10;n101/=9;}
		cout <<n102 <<endl;
	}
	return 0;
}