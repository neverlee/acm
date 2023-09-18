#include<cstdio>
int total;

bool ATime(int mod){
    int pos=1,bei=13,city=total;
    while(city>1){
        if(pos==bei)return false;
        if(pos<bei)--bei;
        --city;
        pos=(pos+mod-1)%city;
    }
    return true;
}
void Go(){
    for(int i=1;;++i){
        if(ATime(i)){
            printf("%ld\n",i);
            return;
        }
    }
}
int main(){
    while(scanf("%ld",&total),total){
        Go();
    }
    return 0;
}
