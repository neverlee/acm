#include <iostream>
using namespace std;
int main()
{
    int result[12];
    
    int a,b;
    while(cin >>a >>b) 
    {
        int final_result = 0;
        int num_of_surplus = 5 * b / (a + b);
        int num_of_deficit = 5 * a / (a + b);
        if(num_of_surplus + num_of_deficit != 5)
            num_of_deficit++;
        else{
            num_of_deficit++;
            num_of_surplus--;
        }
        for(int i=0; i < num_of_surplus; i++){result[i] = a;}
        for(int j=num_of_surplus; j < 5; j++){result[j] = -b;}
        for(int k=5; k < 12; k++){result[k] = result[k % 5];}
        for(int i=0;i<12;i++){final_result += result[i];}
        if(final_result > 0){cout <<final_result <<endl;}
        else{cout <<"Deficit" <<endl;}
    }
    return 0;
}
