#include <iostream>
using namespace std;
long num1,num2;
const long MAX=1000001;
long modn[MAX];

void find()
{
    long i=num2-1,j;
    for(j=i-1;j>=0;j--)
        if(modn[i]==modn[j])
            break;
    long d=i-j;
    for(i=i-1;i>0;i--)
        if(modn[i]!=modn[i-d])
            break;
    i=i-d+1;
    cout <<i <<" " <<d <<endl;
}

void count()
{
    long i;
    modn[0]=num1;
    for(i=1;i<num2;i++)
    {
        num1*=10;
        num1%=num2;
        modn[i]=num1;
        if(num1==0)//\xc8\xe7\xb9\xfb\xc4\xdc\xb3\xfd\xbe\xa1\xd4\xf2
        {
            cout <<i <<" 0" <<endl;
            return;
        }
    }
    find();
}

int main()
{
    for(;;)
    {
        cin >>num1 >>num2;
        if(num1==0)break;
        count();
    } 
    return 0;
}
