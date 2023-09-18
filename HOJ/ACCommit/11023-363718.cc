#include<stdio.h> 
#define N 1000002 
int main() 
{ 
    int i,b[100],kleft,f;  
    __int64 sum; 
    char a[N]; 
    for(i=\'0\';i<=\'9\';i++)  b[i]=i-\'0\'; 
    for(i=\'A\';i<=\'Z\';i++)  b[i]=i-\'A\'+10; 
    
    while(gets(a)!=NULL) 
    {                         
     kleft=1; sum=0; 
     for(i=0;a[i];i++){           
      if(b[a[i]]>kleft)  kleft=b[a[i]];   
      sum+=b[a[i]];  
     }             
    f=0; 
    for(i=kleft;i<=35;i++)   
        if(sum%i==0)  
          {printf("%d\n",i+1);f=1;break;} 
    if(f==0)   printf("No solution.\n");   
    }   
    return 0; 
} 