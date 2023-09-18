#include"stdio.h" 
#include"string.h" 
int main(){ 
    char a[205]; 
    char b[205]; 
     
    while(gets(a)){ 
    int i,j=0,n,flag=0; 
     for(i=0;i<strlen(a);i++) 
       if((a[i]>=\'a\'&&a[i]<=\'z\')||(a[i]>=\'A\'&&a[i]<=\'Z\')) 
          b[j++]=a[i]; 
     
      n=j;    
    for(j=0;j<=n/2;j++) 
    if(b[j]==b[n-j-1]) 
       flag=1; 
    else { 
         flag=0; 
         break; 
         } 
     
    if(flag) 
          printf("YES\n"); 
    else 
          printf("NO\n"); 
}       
     
    return 0; 
}  