#include<iostream>
using namespace std;
int main()
{
int s,p,y,j,t,x,addp,addy;
while(cin>>s>>p>>y>>j)
{
t=12+j-p-y;
addp=addy=0;
x=t%3;
if(s+p==y)
{

if(x==1)
addy++;
if(x==2)
{
addy++;
addp++;
}
}
else{
if(x==1)
addp++;
if(x==2)
{
addy++;
addp++;
}
}
x=t/3;
cout<<y+x+addy<<" "<<p+x+addp<<" "<<x<<endl;
}
return 0;
}
