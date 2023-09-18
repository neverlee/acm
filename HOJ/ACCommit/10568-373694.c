import java.lang.*;
import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int[] fac = new int[12];
        fac[0]=1;fac[1]=1;
        for(int i=2;i<=9;++i)fac[i]=fac[i-1]*(i);
        int num;
        while((num=cin.nextInt())>=0){
            if(num==0){
                System.out.println("NO");
                continue;
            }
            for(int i=9;i>=0;--i){
                if(num>=fac[i])num-=fac[i];
            }
            if(num==0)System.out.println("YES");
            else System.out.println("NO");
        }
    }
}