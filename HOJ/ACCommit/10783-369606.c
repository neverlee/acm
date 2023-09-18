import java.util.*;
import java.math.*;
import java.lang.*;

public class Main{
    static BigInteger[][] combo = new BigInteger[26][];
    static StringBuilder str;
    public static void init(){
        for(int i=0;i<26;i++){
            int k=i;
            combo[i] = new BigInteger[i+1];
            combo[i][0] = new BigInteger("1");
            for(int j=1;j<=i;j++){
                combo[i][j]=combo[i][j-1].multiply(new BigInteger(Integer.toString(k--)));
            }
        }
    }
    public static void main(String[] args){
        init();
        int length,temp,ctemp,m,n;
        BigInteger result;
        Scanner cin = new Scanner(System.in);
        while((length=cin.nextInt())!=0){
            str = new StringBuilder(cin.next());
            result = new BigInteger("0");
            n=25;m=str.length()-1;
            for(int i=0;i<str.length();i++)
            {
                temp = str.charAt(i)-\'A\';
                BigInteger cal = new BigInteger(Integer.toString(temp));
                cal = cal.multiply(combo[n--][m--]);
                result = result.add(cal);
                for(int j=i+1;j<str.length();j++){
                    ctemp=str.charAt(j);
                    if(str.charAt(i)<ctemp){
                        str.setCharAt(j,(char)(ctemp-1));
                    }
                }
            }
            System.out.println(result);
        }
    }
}