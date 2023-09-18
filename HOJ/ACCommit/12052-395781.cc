#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned char uchar;
uchar ct, result[10000];
int main(){
    int iTest, iCase;
    int ilen, ir, past;
    scanf("%ld",&iTest);
    while(iTest--){
        scanf("%ld%ld",&iCase,&ilen);
        ir=0;
        for(int i=0;i<ilen;++i){
            scanf("%2X",&ct);
            if(ct>127){
                past=ct-125;
                scanf("%2X",&ct);++i;
                for(int j=0;j<past;++j)result[ir++]=ct;
            }else{
                past=ct+1;
                for(int j=0;j<past;++j){
                    scanf("%2X",&ct);++i;
                    result[ir++]=ct;
                }
            }
        }
        printf("%ld %ld", iCase, ir);
        for(int i=0;i<ir;++i){
            if(i%40==0)putchar(\'\n\');
            printf("%02X",result[i]);
        }
        putchar(\'\n\');
    }
}
