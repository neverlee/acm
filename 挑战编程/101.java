import java.util.Scanner;
public class Main {
	static final int SIZE=1000001;
	static int[] result=new int[SIZE];

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		result[1]=1;
		int length;long temp;
		for(int i=2;i<SIZE;i++){
			temp=i;length=0;
			while(temp>=i){
				if(temp%2==0)temp/=2;
				else temp=temp*3+1;
				length++;
			}
			result[i]=length+result[(int)temp];
		}
		int x,y,maxl,x1,y1;
		while(cin.hasNextInt()){
			x1=x=cin.nextInt();y1=y=cin.nextInt();
			if(x>y){
				x=y1;y=x1;
			}
			maxl=1;
			for(int i=x;i<=y;i++){
				maxl=result[i]>maxl?result[i]:maxl;
			}
			System.out.println(x1+" "+y1+" "+maxl);
		}
	}
}