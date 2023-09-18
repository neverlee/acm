#include<cstdio>
int h[10001], n, l, t, r, m;
int s,e;char c;
int main(){
    scanf("%ld%ld",&n,&l);
    while(n--){
        while(c=getchar(),c<\'0\');
        t=c-\'0\';
        while(c=getchar(),c>=\'0\')t=t*10+c-\'0\';
        ++h[t];
    }
    r=0;
    for(s=0,e=10000;s<=e;){
        if(s==e){
            if(s<<1<=l)r+=(h[s]/2+h[s]%2);
            else r+=h[s];
            break;
        }
        if(h[s]==0)++s;
        else if(h[e]==0)--e;
        else if(h[s]&&h[e]){
            if(s+e<=l){
                m=h[s]<h[e]?h[s]:h[e];
                h[s]-=m;h[e]-=m;
                r+=m;
            }else{
                r+=h[e];
                h[e]=0;
            }
        }
    }
    printf("%ld",r);
}
