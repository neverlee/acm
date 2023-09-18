// 10965-Electrical Outlets.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <cstdio>

int main()
{
    int ncase,num,total,tn;scanf("%ld",&ncase);
    while(ncase--)
    {
        total=0;
        scanf("%ld",&num);
        for(int i=0;i<num;i++)
        {
            scanf("%ld",&tn);
            total+=tn;
        }
        printf("%ld\n",total-num+1);
    }
    return 0;
}

