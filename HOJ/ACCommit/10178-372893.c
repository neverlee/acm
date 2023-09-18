import java.lang.*;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int ncase = cin.nextInt();
        int a,b,k;
        while(ncase-->0){
            a=cin.nextInt();
            b=cin.nextInt();
            while(a%b!=0){
                k=a%b;
                a=b;b=k;
            }
            System.out.println(b);
        }
    }
}