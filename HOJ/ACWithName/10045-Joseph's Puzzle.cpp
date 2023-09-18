#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	short person[101];
	short Nn,Mn;
	while(1)
	{
		cin >>Nn >>Mn;
		if(Nn==0)return 0;
		for(int i=1;i<=Nn;i++)cin >>person[i];
		short t=Mn%Nn;
		if(!t)t=Nn;
		cout <<t;
		short count=Nn;
		do{
			Mn=person[t];person[t]=0;
			count--;
			if(Mn>count)Mn=Mn%count;
			if(!Mn)Mn=count;
			while(Mn)
			{
				t++;if(t>Nn)t=1;
				if(person[t]){Mn--;}
			}
			cout <<" " <<t;
		}while(count>1);
		cout <<endl;
	}
}