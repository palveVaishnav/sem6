import java.util.*;
import java.io.*;

public class A1Q3
{
	public static void main(String a[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("\nEnter the number of flavors: ");
		int n=Integer.parseInt(br.readLine());
		int price;
		String s;
		Hashtable<String,Integer> flav= new Hashtable <String, Integer>();

		for(int i=0;i<n;i++)
		{
			System.out.print("\nEnter the name flavor: ");
			s=br.readLine();
			if(flav.containsKey(s))
			{
				System.out.println("\nDuplicate entries are not allowed: ");
				i--;
				continue;
			}

			System.out.println("\nEnter the price of flavor: ");
			price=Integer.parseInt(br.readLine());
			flav.put(s,price);
		}
		while(true)
		{
			System.out.print("\n1.Search specific flavor.\n2.Sort all flovors\n3.Exit\n4.Enter your choice\n");
			int c=Integer.parseInt(br.readLine());
			switch(c)
			{
				case 1: System.out.print("\nEnter the name of flavor: ");
					s=br.readLine();
					if(flav.containsKey(s))
					{
						System.out.print("\nFound\nFlavor Name:"+s+"\nPrice:"+flav.get(s));
					}
					else
					{
						System.out.print("\nFlavor not found");
					}
					break;
				case 2:TreeMap<String,Integer> tm=new TreeMap<String,Integer>(flav);
				       Set<String> keys=tm.keySet();
				       Iterator<String> itr=keys.iterator();
				       System.out.print("\nFlavor in sorted order:\n");
				       
					while(itr.hasNext())
					{
						String i=itr.next();
						System.out.println(i+" "+tm.get(i));
					}
				       break;
				case 3:System.exit(0);
			}
		}
	}
}

