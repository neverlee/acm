//10422-»ùÒò±àÂë

import java.io.*;
import java.util.*;
import java.lang.*;
public class j10422
{
	static String gene;
	static int[] vinit;
	static char[] result;
	static int pos;
	
	private static void Vinit()
	{
		vinit=new int[gene.length()];
		vinit[0]=1;
		//System.out.print(vinit[0]+" ");
		for(int i=1;i<gene.length()-1;i++)
		{
			if(gene.charAt(i-1)==gene.charAt(i))
				vinit[i]=vinit[i-1]+1;
			else vinit[i]=1;
			//System.out.print(vinit[i]+" ");
		}
		//System.out.println();
	}
	
	private static void DiGui(int start,int end)
	{
		//System.out.println("start="+start+"  end="+end);
		if(end-start<=vinit[end-1])
			result[pos++]=gene.charAt(start)=='0'?'A':'B';
		else
		{
			result[pos++]='C';
			DiGui(start,(start+end)/2);
			DiGui((start+end)/2,end);
		}
	}
	
	public static void main(String args[])
	{
		Scanner jin = new Scanner(System.in);
		jin.useDelimiter("\n");
		while(jin.hasNext())
		{
			pos=0;
			gene=jin.next();
			//System.out.println(gene.length()-1);
			Vinit();
			result=new char[gene.length()*3];
			DiGui(0,gene.length()-1);
			for(int i=0;i<pos;i++)
				System.out.print(result[i]);
			System.out.println();
		}
	}
}