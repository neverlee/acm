import java.lang.*;
import java.util.*;

class Point{
    public int x,y;
    public Point(long num){

        num*=2;
        long res = (long)Math.sqrt((double)num);
        long tmp;
        if(num>res*(res+1))++res;
        tmp=res*(res-1);
        x=(int)res;y=(int)(num-tmp)/2;
    }
}
public class Main {
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int[] three = new int[3];
        Point[] pos = new Point[3];
        boolean istr;
        while(cin.hasNextInt()){
            for(int i=0;i<3;++i){
                three[i]=cin.nextInt();
            }
            System.out.print(three[0]+" "+three[1]+" "+three[2]);
            Arrays.sort(three);
            for(int i=0;i<3;++i){
                pos[i] = new Point(three[i]);
            }
            istr=false;
            if(pos[1].x==pos[2].x && pos[0].y==pos[1].y 
                && pos[2].y-pos[1].y==pos[1].x-pos[0].x){
                istr=true;
            }
            if(pos[0].x==pos[1].x && pos[1].y==pos[2].y 
                && pos[1].y-pos[0].y==pos[2].x-pos[1].x){
                istr=true;
            }
            if(istr){
                System.out.println(" are vertices of an equilateral triangle.");
            }else{
                System.out.println(" are not vertices of an equilateral triangle.");
            }
        }
    }
}