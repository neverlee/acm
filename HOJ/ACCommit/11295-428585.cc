#include <iostream>
using namespace std;

int main()
{
    char a[1001];
    while (~scanf("%s",a)) {
        int i,k=strlen(a),max=0,num=0,flag=0;
        for (i=0; i<k; i++)
            if (a[i]>=\'0\'&&a[i]<=\'9\') {
                if (a[i]-\'0\'>max)
                    max=a[i]-\'0\';
                num=num+a[i]-\'0\';
            }
            else if (a[i]>=\'a\'&&a[i]<=\'z\') {
                if (a[i]-\'a\'+36>max)
                    max=a[i]-\'a\'+36;
                num=num+a[i]-\'a\'+36;
            }
            else if (a[i]>=\'A\'&&a[i]<=\'Z\') {
                if (a[i]-\'A\'+10>max)
                    max=a[i]-\'A\'+10;
                num=num+a[i]-\'A\'+10;
            }
        for (i=2,flag=0; i<=62; i++)
            if (num%(i-1)==0&&i>max) {
                flag=1;
                break;
            }
        if (flag)
            cout << i << \'\n\';
        else cout << "such number is impossible!\n";
    }
    return 0;
} 