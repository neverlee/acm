#include<cstdio>
#include<algorithm>
using namespace std;
int len,num;
int there[12]={1};
struct Thing{
    int value,space;
    Thing(){value=space=0;}
    bool operator<(Thing &t){
        return value<t.value;
    }
}thi[2050];
struct Have{
    short con;
    bool operator<(const Have&h)const{
        return thi[con]<thi[h.con];
    }
}has[2050];
void Init(){
    char str[100];
    for(int i=1;i<12;++i)there[i]=there[i-1]<<1;
    for(len=0;gets(str),str[0]!=\'$\';++len){
        sscanf(str, "%ld%ld", &thi[there[len]].value
            , &thi[there[len]].space);
    }
    for(int i=0;i<there[len];++i){
        has[i].con=i;
        for(int j=0;j<len;++j){
            if(there[j]&i&&i!=there[j]){
                thi[i].value+=thi[there[j]].value;
                thi[i].space+=thi[there[j]].space;
            }
        }
    }
    sort(has, has+there[len]);
}
void Result(){
    for(int i=there[len]-1;i>0;--i){
        if(thi[has[i].con].space<=num){
            printf("%ld ",thi[has[i].con].value);
            int tmp=has[i].con;
            for(int j=0;j<len&&tmp;++j){
                if(there[j]&tmp){
                    printf("%c",\'A\'+j);
                    tmp-=there[j];
                    if(tmp)putchar(\',\');
                }
            }
            printf("\n");
            return;
        }
    }
    printf("0\n");
}
int main(){
    Init();
    while(scanf("%ld",&num)!=EOF){
        Result();
    }
    return 0;
}