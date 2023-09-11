#include <cstdio>
#include <algorithm>
using namespace std;
struct Inv{
    int st, ed;
};
bool cmp(const Inv &a, const Inv &b){
    return a.st<b.st||(a.st==b.st&&a.ed<b.ed);
}
Inv task[10010], same[10010];
int used[10010];
int time, amount, section;
int i,j;
int min(int a, int b) { return a<b?a:b; }
void init() {
    scanf("%d%d", &time, &amount);
    task[0].st=task[1].ed=0;
    task[amount+1].st=task[amount+1].ed=10010;
    for(i=1; i<=amount; ++i) {
        scanf("%d%d", &task[i].st, &task[i].ed);
        task[i].ed+=task[i].st;
    }
    sort(task+1, task+amount+1, cmp);
    section=1;
    same[0].st=0;
    for(i=0; i<=amount; ++i) {
        if(task[i].st!=task[i+1].st) {
            same[section-1].ed=same[section].st=i+1;
            ++section;
        }
    }
    same[section-1].ed=amount+2;
}
 
void work() {
    for(i=1; i<=amount+1; ++i)used[i]=1E6;
    used[0]=0;
    int p,q,r,s;
    for(i=1; i<section; ++i) {
        r=same[i].st;
        s=same[i].ed;
        for(j=0; j<i; ++j) {
            p=same[j].st;
            q=same[j].ed;
            if(p<q&&task[r].st>=task[p].ed) {
                int k;
                for(k=r; k<s; ++k) {
                    used[k]=min(used[k], task[k].ed-task[k].st+used[p]);
                }
                for(k=p; k<q&&task[k].ed<=task[r].st; ++k);
                same[j].st=k;
            }
        }
    }
    printf("%d", time-used[amount+1]);
}
int main() {
    init();
    work();
     
}