//j10615.java -Word Frequences
import java.util.*;
import java.io.*;
public class j10615
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		String[] aystr;
		int total=0;
		HashSet<String> mhs = new HashSet<String>();
		while(cin.hasNextLine())
		{
			aystr = cin.nextLine().split("[\\W+[\\d]]");
			for(String str : aystr)
			{
				if(str.length()>0)
				{
					++total;
					mhs.add(str.toLowerCase());
				}
			}
		}
		System.out.println("different words:"+mhs.size());
		System.out.println("total words:"+total);
	}
}