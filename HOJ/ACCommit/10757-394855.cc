#include<cstdio>
#include<algorithm>
using namespace std;
int iNumber, iSat, igWait[1001], igServer[101], iWaitTime, iMin;
int main(){
    scanf("%ld%ld",&iNumber,&iSat);
    for(int i=0;i<iNumber;++i)scanf("%ld",igWait+i);
    sort(igWait, igWait+iNumber);
    for(int i=0;i<iNumber;++i){
        iMin=0;
        for(int j=1;j<iSat;++j)
            if(igServer[j]<igServer[iMin])iMin=j;
        iWaitTime+=igServer[iMin];
        igServer[iMin]+=igWait[i];
    }
    printf("%ld", iWaitTime);
    return 0;
}
