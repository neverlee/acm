#include <cstdio>
int main() {
    int k,l,n,m,mod,hour,min;
    double day,Second;
    while(-1!=scanf("%d%d",&k,&l)) {
        m=k;
        n=l;
        if(k>l) { n=k; m=l; }
        mod=43200%(n-m);
        day=43200.0/(n-m);
        Second=mod*1.0*86400/(n-m);
        Second-=day*m;
        while(Second<0)
            Second+=43200;
        mod=(int)Second;
        mod%=43200;
        hour=mod/3600;
        hour%=12;
        if(hour==0)
            hour=12;
        Second=((mod%3600)*1.0)/60;
        min=Second*10;
        if(min%10>=5)
            min+=10;
        min/=10;
        if(min>=60) {
            min%=60;
            hour++;
            if(hour==13) hour=1;
        }
        printf("%d %d %02d:%02d\n",k,l,hour, min);
    }
    return 0;
}