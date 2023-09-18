#include "stdafx.h"
#include<stdio.h>
#define N 5002 
int main() 
{ 
    static int a[N];int i,left,right,high,max=0;
    while(scanf("%d %d %d",&left,&high,&right)==3) 
    {
    	for(i=left;i<right;i++)
        if(a[i]<high)a[i]=high;
		if(right>max)max=right;
    }
    for(i=1;i<=max;i++) 
    {
		if(a[i]!=a[i-1])
		{printf("%d %d",i,a[i]);if(i!=max)putchar(' ');}
    } 
    return 0; 
} 