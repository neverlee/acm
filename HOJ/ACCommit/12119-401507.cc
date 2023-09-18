#include<cstdio>
#include<cstring>
char str[12];
int len, src, tag;
void Deal() {
    int i,j,mid=(len>>1)-1;
    i=mid;j=mid+1;
    if(len%2==1) {++j;++mid;}
    for(;i>=0;--i,++j){
        if(str[i]>str[j])break;
        else if(str[i]<str[j]) i=-2;
    }
    if(i<-1){
        ++str[mid];
        for(i=mid;i>0&&str[i]>\'9\';--i){
            ++str[i-1];str[i]=\'0\';
        }
    }
    for(i=0,j=len-1;i<j;++i,--j)str[j]=str[i];
    sscanf(str, "%ld", &tag);
    printf("%ld\n", tag-src);
}
int main(){
    while(scanf("%s",str)){
        sscanf(str, "%ld", &src );
        if( strcmp(str, "0")==0 )break;
        len=strlen(str);
        Deal();
    }
}
