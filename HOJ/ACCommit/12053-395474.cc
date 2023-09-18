#include<cstdio>
#include<algorithm>
using namespace std;
__int64 red[10][80];
void Init(){
    for(int i=1;i<80;++i)red[9][i]=1;
    for(int i=0;i<10;++i)red[i][0]=1;
    for(int i=8;i>=0;--i)
        for(int j=1;j<80;++j)
            red[i][j]=red[i+1][j]+red[i][j-1];
}
int main(){
    int iTest, iCase;
    int ibase;
    Init();
    scanf("%ld",&iTest);
    while(iTest--){
        scanf("%ld%ld",&iCase,&ibase);
        printf("%ld %I64d\n",iCase, red[0][ibase]);
    }
}
