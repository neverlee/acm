#include <iostream>  
#include <string>  
#include <cmath>  
using namespace std;  
  
__int64 check = 23, result_t,final;  
__int64 num[50],op[50];  
  
//pow  
__int64 pow_int( __int64 a,__int64 b )  
{  
    __int64 k = 1;  
    for( int i = 0;i < b;i++ )
    {
        k *= a;
    }
    return k;  
}  
//\xb6\xd4\xd5\xbb\xb5\xc4\xb6\xa5\xc1\xbd\xb8\xf6\xca\xfd\xbd\xf8\xd0\xd0op  
void cul( int p,int op )  
{  
    if( op == 0 ) num[p-1] = num[p-1]+num[p];  
    if( op == 1 ) num[p-1] = num[p-1]-num[p];  
    if( op == 2 ) num[p-1] = num[p-1]*num[p];  
    if( op == 5 ) num[p-1] = pow_int( num[p-1],num[p] );  
}  
//\xd6\xf7\xd2\xaa\xba\xaf\xca\xfd  
__int64 result( string str )  
{  
    int op_nxt, len = str.length(),  
        p = -1, q = -1;         //\xca\xfd\xd5\xbb\xba\xcdop\xd5\xbb\xb5\xc4\xd6\xb8\xd5\xeb  
    __int64 num_nxt = 0;  
    for( int i = 0;i < len;i++ )  
    {  
        if( str[i] == \'a\' )  
        {  
            num[++p] = check;  
        }  
        else if( str[i] >= \'0\' && str[i] <= \'9\' )  
        {  
            num_nxt = num_nxt*10 + (str[i]-\'0\');  
        }  
        else if( str[i] != \' \' )  
        {  
            if( num_nxt != 0 )   
            {  
                num[++p] = num_nxt;  
                num_nxt = 0;  
            }  
            if( str[i] == \'+\' ) op_nxt = 0;  
            if( str[i] == \'-\' ) op_nxt = 1;  
            if( str[i] == \'*\' ) op_nxt = 2;  
            if( str[i] == \'^\' ) op_nxt = 5;  
            if( str[i] == \'(\' ) op_nxt = 6;  
            if( str[i] == \')\' ) op_nxt = 7;  
            if( op_nxt == 6 )  
            {  
                op[++q] = op_nxt;  
            }  
            else if( op_nxt == 7 )  
            {  
                while( q >= 0 && op[q--] != 6 )  
                {  
                    cul( p--,op[q+1] );  
                }  
            }  
            else   
            {  
                //\xd3\xc5\xcf\xc8\xbc\xb6\xb8\xdf\xb5\xc4op\xb3\xf6\xd5\xbb  
                while( q >= 0 && op[q] <= 5 && op[q]/2 >= op_nxt/2 )  
                {  
                    cul( p--,op[q--] );  
                }  
                op[++q] = op_nxt;  
            }  
        }  
    }  
    //\xbc\xc7\xb5\xc3\xd7\xee\xba\xf3\xd2\xaa\xc7\xe5\xbf\xd5\xd5\xbb  
    if( num_nxt != 0 )  
    {  
        num[++p] = num_nxt;  
        num_nxt = 0;  
    }  
    while( q >= 0 )  
    {  
        cul( p--,op[q--] );  
    }  
    return num[0];  
}  
// atoi\xb2\xbb\xc8\xc3\xd3\xc3 sicily  
int myatoi( string str )  
{  
    int result = 0, len = str.length();  
    for( int i = 0; i < len; i++ )  
    {  
        result = result*10 + (str[i]-\'0\');  
    }  
    return result;  
}  
int main(){
    string str1,str2;  
    int n;  
    final = 0;  
    getline(cin,str1);  
    getline(cin,str2);  
    n = myatoi( str2 );  
  
    result_t = result( str1 );  
      
    while( n-- )  
    {  
        getline(cin,str2);  
        if( result(str2) == result_t )  
        {
            cout<<(char)(\'A\'+final);  
        }
        final++;
    }
    cout<<endl;  
    return 0;  
} 