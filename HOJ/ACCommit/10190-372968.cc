#include<cstdio>
short count[26]={0},k;
char str[100];
void Space(int n){while(n-->0)putchar(\' \');}
int main(){
    for(int i=0;i<4;++i){
        gets(str);
        for(int j=0;str[j];++j){
            k=str[j]-\'A\';
            if(k>=0&&k<26)++count[k];
        }
    }
    int max=0;
    for(int i=0;i<26;++i)max=max>count[i]?max:count[i];
    int fi;
    for(int i=max;i>0;--i){
        fi=0;
        if(count[0]>=i){
            putchar(\'*\');
            fi=0;
        }else{
            putchar(\' \');
        }
        for(int j=1;j<26;++j){
            if(count[j]>=i){
                Space((j-fi)*2-1);
                fi=j;
                putchar(\'*\');
            }
        }
        putchar(\'\n\');
    }
    putchar(\'A\');
    for(int i=1;i<26;++i)printf(" %c",\'A\'+i);
    putchar(\'\n\');
    return 0;
}