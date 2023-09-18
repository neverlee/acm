#include<cstdio>
int rect[1010][1010],count;
char cmp[1010];
void Init(){
    char str[100];int a,b;
    for(int i=0;i<count;++i)rect[i][0]=0;
    for(int i=2;i<=count;++i){
        gets(str);
        if(\'N\'==str[0]){
            sscanf(str+2, "%ld", &a);
            rect[a][++rect[a][0]]=i;
            cmp[i]=2;
        }else{
            sscanf(str+2, "%ld %ld", &a, &b);
            rect[a][++rect[a][0]]=i;
            cmp[i]=(char)b;
        }
    }
}
char cabs(char c){return c>0?c:-c;}
char Recursive(int pos, char status){
    char two[2]={0};int kp;
    for(int i=1;i<=rect[pos][0];++i){
        kp=rect[pos][i];
        if(cmp[kp]==2){
            cmp[kp]=Recursive(kp, -status);
        }
        if(cmp[kp]==status){
            return status;
        }else{
            two[cabs(cmp[kp])]=1;
        }
    }
    if(two[0])return 0;
    if(two[1])return -status;
    return 0;
}
int main(){

    while(scanf("%ld%*c",&count),count){
        Init();
        char res = Recursive(1, 1);
        if(res==1)putchar(\'+\');
        printf("%ld\n",(int)res);
    }
    return 0;
}