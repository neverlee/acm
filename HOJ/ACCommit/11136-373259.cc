#include<cstdio>
#include<cstring>
typedef unsigned char uchar;
uchar str[1000];
int len;
uchar reps[64];
void Init(){
    for(int i=0;i<26;++i){
        reps[i]=\'A\'+i;
        reps[i+26]=\'a\'+i;
    }
    for(int i=0;i<10;++i){
        reps[i+52]=\'0\'+i;
    }
    reps[62]=\'+\';reps[63]=\'/\';
}
unsigned GetCode(uchar *s, int i){
    if(i==0)return s[0]>>2;
    if(i==1)return ((s[0]&3)<<4)|(s[1]>>4);
    if(i==2)return ((s[1]&15)<<2)|(s[2]>>6);
    if(i==3)return s[2]&63;
}
int main(){
    Init();
    int ncase;scanf("%d%*c",&ncase);
    while(scanf("%[^\n]%*c",str)!=EOF){
        len=strlen((char*)str);
        str[len+1]=0;
        int i;
        for(i=0;i+3<=len;i+=3){
            for(int j=0;j<4;++j)
                putchar(reps[GetCode(str+i,j)]);
        }
        if(len-i==1){
            putchar(reps[GetCode(str+i,0)]);
            putchar(reps[GetCode(str+i,1)]);
            printf("==");
        }
        if(len-i==2){
            putchar(reps[GetCode(str+i,0)]);
            putchar(reps[GetCode(str+i,1)]);
            putchar(reps[GetCode(str+i,2)]);
            putchar(\'=\');
        }
        putchar(\'\n\');
    }
    return 0;
}