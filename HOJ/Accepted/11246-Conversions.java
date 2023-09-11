//11246-Conversions
import java.lang.*;
import java.util.*;
import java.text.DecimalFormat;
public class Main {
	public static void main(String[] args) {
		int ncase;
		double[] trans=new double[]{2.2046,0.4536,0.2642,3.7854};
		String[] dws=new String[]{"kg","lb","l","g"};
		Scanner cin = new Scanner(System.in);
		ncase = cin.nextInt();
		double weight;
		String dw;
		DecimalFormat df = new DecimalFormat("0.0000");
		for(int text=1;text<=ncase;text++){
			weight = cin.nextDouble();
			dw = cin.next();
			for(int i=0;i<4;i++){
				int k=1;
				if(dw.equals(dws[i])){
					weight*=trans[i];
					if(i%2!=0)k=-1;
					dw=dws[i+k];
					break;
				}
			}
			System.out.println(text+" "+df.format(weight)+" "+dw);
		}
	}
}