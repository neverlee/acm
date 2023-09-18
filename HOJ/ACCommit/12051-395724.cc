#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned char uchar;
uchar str[6000], result[10000];
int NextSame(uchar *str){
    int h=1;
    for(;str[0]==str[h]&&h<130;++h);
    return h;
}
int main(){
    int iTest, iCase;
    int ilen, ir, past;
    scanf("%ld",&iTest);
    while(iTest--){
        scanf("%ld%ld",&iCase,&ilen);
        for(int i=0;i<ilen;++i)scanf("%2X",str+i);
        str[ilen]=!str[ilen-1];
        ir=0;
        for(int i=0;i<ilen;){
            int h;
            if((h=NextSame(str+i))>2){
                result[ir]=(h-3)|128;
                result[ir+1]=str[i];
                ir+=2;
                i=i+h;
            }else{
                int j,k;
                past=h;
                for(j=i+h;j<ilen;){
                    h=NextSame(str+j);
                    if(h<3&&past+h<=128){past+=h;j+=h;}
                    else break;
                }
                result[ir++]=past-1;
                for(k=past;k>0;--k)result[ir++]=str[j-k];
                i+=past;
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
