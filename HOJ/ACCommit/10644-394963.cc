#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned __int64 uint;
vector<uint> remain;
vector<int> width;
int GetSize(uint num){
    int i=0;
    do{++i;num/=10;}while(num>0);
    return i;
}
void PutSyb(int num, char c){for(int i=0;i<num;++i)putchar(c);}
int main(){
    remain.reserve(100);
    width.reserve(100);
    uint ip,iq,itp,ifront;
    for(int iTest=1;scanf("%I64u%I64u",&ip,&iq),ip;++iTest){
        printf("Case %ld:\n%I64u / %I64u\n", iTest, ip, iq);
        while(iq){
            itp=ip%iq;
            remain.push_back(ip/iq);
            ip=iq;iq=itp;
        }
        if(remain.back()>1){
            remain.back()-=1;
            remain.push_back(1);
        }
        for(int i=0;i<remain.size();++i)
            width.push_back(GetSize(remain[i]));
        for(int i=width.size()-2;i>=0;--i){
            width[i]+=width[i+1]+3;
        }
        ifront=0;
        for(int i=0;i<width.size()-1;++i){
            PutSyb(width[0]-width[i+1]+(width[i+1]-1)/2, \'.\');
            putchar(\'1\');
            PutSyb((width[i+1])/2, \'.\');
            putchar(\'\n\');
            PutSyb(ifront, \'.\');
            printf("%I64d.+.", remain[i]);
            PutSyb(width[i+1], \'-\');
            ifront+=width[i]-width[i+1];
            putchar(\'\n\');
        }
        PutSyb(width[0]-1, \'.\');
        printf("1\n");
        remain.clear();
        width.clear();
    }
    return 0;
}
