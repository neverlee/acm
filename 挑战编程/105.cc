#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace::std;
int M=0,N=0,x,y,x1,y1,x2,y2;
char g[300][300]={'\0'},cmds,c,name[300]={'\0'};
bool vis[300][300]={false};

int mins(int a,int b)
{
if(a>b) a=b;
return a;
}

void find(int i,int j,char col,char F)
{
if(g[i][j]!=col || vis[i][j]  || !M || !N) 
return;
vis[i][j]=true;
g[i][j]=F;
find(i-1,j,col,F);
find(i+1,j,col,F);
find(i,j-1,col,F);
find(i,j+1,col,F);
}
int main()
{
int tmp;
while(true)
{
scanf("%c",&cmds);
if(cmds=='X') break;
if(cmds=='I')
{
scanf("%d %d\n",&M,&N);
for(int i=1;i<=N;i++)
for(int j=1;j<=M;j++) 
g[i][j]='O';
}else if(cmds=='C')
{
for(int i=1;i<=N;i++)
for(int j=1;j<=M;j++) 
g[i][j]='O';
}
else if(cmds=='L')
{
scanf("%d %d %c\n",&x,&y,&c);
if(y<=N && x<=M)
g[y][x]=c;
}else if(cmds=='V')
{
scanf("%d %d %d %c\n",&x,&y1,&y2,&c);
if(y1>y2) 
{ 
tmp=y1;
y1=y2;
y2=tmp; 
}
y1=mins(y1,N); 
y2=mins(y2,N); 
x=mins(x,M);
for(int i=y1;i<=y2;i++)
g[i][x]=c;
}else if(cmds=='H')
{
scanf("%d %d %d %c\n",&x1,&x2,&y,&c);
if(x1>x2) 
{ 
tmp=x1; 
x1=x2;
x2=tmp; 
}
y=mins(y,N); 
x1=mins(x1,M); 
x2=mins(x2,M);
for(int j=x1;j<=x2;j++)
g[y][j]=c;
}else if(cmds=='K')
{
scanf("%d %d %d %d %c\n",&x1,&y1,&x2,&y2,&c);
if(x1>x2) 
{ 
tmp=x1; 
x1=x2;
x2=tmp; 
}
if(y1>y2) 
{ 
tmp=y1; 
y1=y2; 
y2=tmp; 
}
y1=mins(y1,N);
y2=mins(y2,N);
x1=mins(x1,M); 
x2=mins(x2,M);
for(int i=y1;i<=y2;i++)
for(int j=x1;j<=x2;j++)
g[i][j]=c;
}else if(cmds=='F')
{
scanf("%d %d %c\n",&x,&y,&c);
y=mins(y,N); 
x=mins(x,M);
memset(vis,false,sizeof(vis));
find(y,x,g[y][x],c);
}else if(cmds=='S')
{
scanf("%s",name);
printf("%s\n",name);
for(int i=1;i<=N;i++)
{
for(int j=1;j<=M;j++)
printf("%c",g[i][j]);
printf("\n");
}
}
}
return 0;
}