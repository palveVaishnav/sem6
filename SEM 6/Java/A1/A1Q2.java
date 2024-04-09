import java.util.*;
import java.io.*;

class A1Q2

{
	static BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
	public static void main(String args[]) throws IOException
	{
		LinkedList ll1 = new LinkedList();
		LinkedList ll2 = new LinkedList();
		int n1,n2;
		System.out.print("Enter No. of Elements in Linked List 1:\t");
		n1 = Integer.parseInt(br.readLine());
		System.out.println("Enter Elements in Linked List 1");
		for(int i=0;i<n1;i++)
		{
			System.out.print("Enter Element "+(i+1)+":\t");
			String item = br.readLine();
			if(!ll1.contains(item))
				ll1.add(item);
		}
		System.out.print("Enter No. of Elements in Linked List 2:\t");
		n2 = Integer.parseInt(br.readLine());
		System.out.println("Enter Elements in a Linked List 2");
		for(int i=0;i<n2;i++)
		{
			System.out.print("Enter Element "+(i+1)+":\t");
			String item = br.readLine();
			if(!ll2.contains(item))
				ll2.add(item);
		}
		Collections.sort(ll1);
		Collections.sort(ll2);
		System.out.println("Linked List 1\tLinked List 2");
		System.out.println("\n"+ll1+"\t\t"+ll2);
		
		LinkedList ll3 = new LinkedList();
		for(int i=0;i<ll1.size();i++)
			ll3.add(ll1.get(i));
		
		for(int i=0;i<ll2.size();i++)
			if(!ll1.contains(ll2.get(i)))
				ll3.add(ll2.get(i));
		
		System.out.println("Linked List Operations");
		System.out.println("Union:\t"+ll3);

		LinkedList ll4 = new LinkedList();
		for(int i=0;i<ll1.size();i++)
			ll4.add(ll1.get(i));
		ll4.retainAll(ll2);
		System.out.println("Intersection:\t"+ll4);
		
		if(ll1.size()==ll2.size())
		{
			LinkedList ll5 = new LinkedList();
			System.out.println("Combining Element");
			for(int i=0;i<ll1.size();i++)
			ll5.add(ll1.get(i));
			for(int j=0;j<ll2.size();j++)
			ll5.add(ll2.get(j));
			System.out.println(ll5);
		}
	}
}
