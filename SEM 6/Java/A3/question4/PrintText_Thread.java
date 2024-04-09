//final
import java.util.Scanner;
public class PrintText_Thread extends Thread
{

	private final String text;
	private final int n;
	public PrintText_Thread (String text,int n)
	{
		this.text=text;
		this.n=n;
	}
	//@Override
	public void run()
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(text);
			
		}
	}
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the value of n :");
		int n=sc.nextInt();
		System.out.println("Enter the thread 1 :\t");
		String s1=sc.next();
		System.out.println("Enter the thread 2 :\t");
		String s2=sc.next();
		System.out.println("Enter the thread 3 :\t");
		String s3=sc.next();

		Thread t1=new Thread(new PrintText_Thread(s1,n));//s1 s2 s3 are  the threads 
		Thread t2=new Thread(new PrintText_Thread(s2,n));
		Thread t3=new Thread(new PrintText_Thread(s3,n));
		System.out.println("\n\n");

		t1.start();
		t2.start();
		t3.start();
	}


}


