#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t,b,n,i,add,ni;
    float tb;
    int *data,*out;
    cin>>t;
    while(t--)
    {
        add = 0;
        cin>>b>>n;
        data = new int [n];
        out = new int [n];
        for (i = 0; i < n; ++i)
        {
            cin>>data[i];
            add += data[i];
        }
        ni = n;
        if (add < b)
            printf("IMPOSSIBLE\n");
        else
        {
            while(1)
            {
                bool tch = false;
                for (i = 0; i < n; ++i)
                {
                    if (ni == 0) break;
                    tb = ((float)b / (float)ni);
                    if (data[i] != -1)
                    {
                        if( data[i] <= tb )
                        {
                            out[i] = data[i];
                            b -= data[i];
                            ni --;
                            data[i] = -1;
                            tch = true;
                        }
                    }
                }
                if (tch == false)
                {
                    while(1)
                    {
                        
                        int max = 0,rei;
                        for (i = 0; i < n; ++i)
                        {
                            if (data[i] != -1 && data[i] > max)
                            {
                                max = data[i];
                                rei = i;
                            }
                        }
                        
                        if (ni == 0)
                            break;
                        
                        tb = ((float)b / (float)ni);
                        
                        if (fmod(tb,1) != 0.0)
                            out[rei] = (int)tb + 1;
                        else
                            out[rei] = (int)tb;
                        b -= out[rei];
                        data[rei] = -1;
                        ni --;
                    }
                    break;
                }
            }
            
            for (i = 0; i < n; ++i)
            {
                cout<<out[i];
                if (i != n-1)
                    cout<<" ";
            }
            cout<<endl;
        }
        delete [] data;
        delete [] out;
    }
    return 0;
}