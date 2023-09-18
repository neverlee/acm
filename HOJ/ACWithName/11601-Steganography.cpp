// 11601-Steganography.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstring>
using namespace std;
char word[32];
void Init()
{
	word[0]=' ';
	for(int i=1;i<=26;i++)
		word[i]='A'+i-1;
	word[27]='\'';
	word[28]=',';
	word[29]='-';
	word[30]='.';
	word[31]='?';
}

int main()
{
	Init();
	short toc=0;
	char str[1000];
	short tk=16,len;
	int i,j;bool flag = 0;
	while(cin.getline(str,900))
	{
		if(str[0]=='#')
			return 0;
		if(str[0]=='*')
		{
			if(flag)
				cout <<word[toc];
			tk=16;toc=0;flag=0;
			cout <<endl;continue;
		}
		len=strlen(str);
		for(i=0;i<len;i++)
		{
			if(str[i]==' ')
			{
				flag = 1;
				for(j=i+1;j<=len;j++)
					if(str[j]!=' '){break;}
				if(((j-i)%2)==0)
					toc+=tk;
				i=j;tk/=2;
				if(!tk)
				{
					cout <<word[toc];
					tk=16;toc=0;flag=0;
				}
			}
		}
	}
}

