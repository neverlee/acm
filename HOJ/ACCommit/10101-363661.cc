#include <iostream>
using namespace std;
int main()
{
    int result[12];
    int a,b;
    while(cin >>a >>b) 
    {
        int fire = 0;
        int n_surplus = 5*b/(a+b);
        int n_deficit = 5*a/(a+b);
        if(n_surplus + n_deficit != 5)
            n_deficit++;
        else{
            n_deficit++;
            n_surplus--;
        }
        for(int i=0; i < n_surplus; i++){result[i] = a;}
        for(int j=n_surplus; j < 5; j++){result[j] = -b;}
        for(int k=5; k < 12; k++){result[k] = result[k % 5];}
        for(int i=0;i<12;i++){fire += result[i];}
        if(fire > 0){cout <<fire <<endl;}
        else{cout <<"Deficit" <<endl;}
    }
    return 0;
}