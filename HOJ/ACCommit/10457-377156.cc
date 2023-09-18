#include<cstdio>
int total, mod, austin;
int killpos[10010], len;
void Kill(){
    int have=total, pos=-1;
    len=0;
    while(have>1){
        pos=(pos+mod)%have;
        if(pos==austin)pos=(pos+1)%have;
        killpos[len++]=pos;
        if(pos<austin)--austin;
        --pos;--have;
    }
}
void Get(){
    int last=killpos[len-1];
    for(int i=len-2;i>=0;--i){
        if(killpos[i]<=last)++last;
    }
    printf("%ld\n", last+1);
}
int main(){
    int ncase;scanf("%ld",&ncase);
    while(ncase--){
        scanf("%ld%ld%ld", &total, &mod, &austin);
        total;--austin;
        Kill();
        Get();
    }
    return 0;
}
