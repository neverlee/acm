#include<cstdio>
#include<cstring>
int Is(char c){
    if(c==\'H\')return 1;
    else return 0;
}
int main(){
    int iTest, iCase, ia[8], iTmp;
    char str[50];
    scanf("%ld",&iTest);
    while(iTest--){
        memset(ia, 0, sizeof(ia));
        scanf("%ld%s",&iCase,str);
        iTmp=(Is(str[0])<<1)|Is(str[1]);
        for(int i=2;i<40;++i){
            iTmp=(iTmp<<1)|Is(str[i]);
            ++ia[iTmp&7];
        }
        printf("%ld",iCase);
        for(int i=0;i<8;++i)printf(" %ld",ia[i]);
        putchar(\'\n\');
    }
}
