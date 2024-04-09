//final
import java.util.Scanner;
public class q2{
public static void main(String[] args)
{
	Scanner sc=new Scanner(System.in);
	System.out.println("Enter the value of n :");
	int n=sc.nextInt();
	Thread t1=new Thread(new MessagePrinter("Welcome to FY",n));
	Thread t2=new Thread(new MessagePrinter("Welcome to SY",n));
	Thread t3=new Thread(new MessagePrinter("Welcome to TY",n));

	t1.start();
	t2.start();
	t3.start();
}

}

class MessagePrinter implements Runnable
{

	private String message;
	private int n;
	public MessagePrinter(String message,int n)
	{
		this.message=message;
		this.n=n;
	}
	@Override
	public synchronized void run()
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(message);
			try{
				Thread.sleep(1000);
			    }
			catch(InterruptedException e)
			{
				e.printStackTrace();
			}
		}
	}
}


