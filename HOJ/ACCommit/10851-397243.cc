#include<cstdio>
#include<cstring>
int iexp, len, point;
bool syb;
char str[20010], *rs;
int main(){
    while(EOF!=scanf("%ld %s", &iexp, str)){
        if(str[0]==\'-\'){rs=str+1;syb=1;}
        else {rs=str;syb=0;}
        for(;*rs==\'0\';++rs);
        len=strlen(rs);
        char *pt=strchr(rs, \'.\');
        char *p;
        if(pt){
            point=pt-rs;
            for(p=rs+len-1;*p==\'0\'&&p>=rs;*p=0,--p,--len);
            for(int i=point;i<len;++i)rs[i]=rs[i+1];
            --len;
        }else{
            point=len;
            for(p=rs+len-1;*p==\'0\'&&p>=rs;*p=0,--p,--len);
        }
        if(*rs==0){
            puts("0");
            continue;
        }
        if(syb)putchar(\'-\');
        point+=iexp;
        for(;*rs==\'0\';++rs){--point;--len;}
        if(point<=0){
            putchar(\'.\');
            while(point++)putchar(\'0\');
            puts(rs);
        }else if(point<len){
            for(int i=0;i<point;++i)putchar(rs[i]);
            putchar(\'.\');
            puts(rs+point);
        }else{
            printf("%s",rs);
            for(int i=len;i<point;++i)putchar(\'0\');
            putchar(\'\n\');
        }
    }
}
