#include<cstdio>
#include<algorithm>
using namespace std;
int bit[100], len;
int main(){
    int iTest, iCase;
    int ibase, ix,iy,it;
    scanf("%ld",&iTest);
    while(iTest--){
        scanf("%ld%ld%ld%ld",&iCase,&ibase,&ix,&iy);
        if(ix<iy)swap(ix,iy);
        for(len=0;ix;ix/=ibase)
            bit[len++]=ix%ibase;
        for(int i=0;iy;iy/=ibase,++i)
            bit[i]=(bit[i]+iy%ibase)%ibase;
        it=0;
        for(int i=len-1;i>=0;--i)
            it=it*ibase+bit[i];
        printf("%ld %ld\n",iCase, it);
    }
}
