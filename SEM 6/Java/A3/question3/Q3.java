//final
import java.io.*;
import java.util.*;

class part1 extends Thread
{
	public synchronized void run()
	{
		int i=0;
		int num=0;
		String primeNumbers="";
		for(i=1;i<=100;i++)
		{
			int counter=0;
			for(num=i;num>=1;num--)
			{
				if(i%num==0)
				{
					counter=counter+1;
				}
			}
			if(counter==2)
			{
				primeNumbers=primeNumbers+i+" ";
			}
		}
		System.out.println("\nPrime numbers between 1 to 100 are:\n\n "+primeNumbers);
		System.out.println();
	} 
}

class part2 extends Thread
{
	public synchronized void run()
	{
		int n,b,rev=0;
		int N=100;
		System.out.println("Palindrome numbers from 1 to 100:\n");
		for(int i=1;i<=N;i++)
		{
			n=i;
			while(n>0)
			{
				b=n%10;
				rev=rev*10+b;
				n=n/10;													
			}
			if(rev==i)
			{
			//	System.out.println("123");

				System.out.print(i+" ");
			}
			rev=0;
		}
		System.out.println("\n");

	}
}

public class Q3
{
	public static void main(String[] args) throws IOException
	{
		part1 t1=new part1();
		part2 t2=new part2();
		Thread m1=new Thread(t1);
		Thread m3=new Thread(t2);
		Scanner sc=new Scanner(System.in);
		m1.start();
		m3.start();
		try{
			m1.join();
			m3.join();
		}
		catch(InterruptedException e)
		{
			e.printStackTrace();
		} 
	}
}
