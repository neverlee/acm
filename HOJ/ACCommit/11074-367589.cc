#include<stdio.h> 
#include<string.h> 
int a[20001]; 
int main()
{ 
 int n,i,d,t,g;
 scanf("%d",&t); 
 while(t--) 
   {scanf("%d",&n); 
    memset(a,0,sizeof(int)*1*20001); 
    for(i=0;i<n;i++)
      {scanf("%d",&d);
       a[d]++;
      }
    for(i=20000,g=0,d=0;i>0;i--)
      {d+=a[i];
       a[0]+=(d/3-g)*i;
       g=d/3;
      }
    printf("%d\n",a[0]);
   }
 return 0;
}