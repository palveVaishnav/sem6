import java.io.*;
import java.util.*;

public class A1Q1
{
	public static void main( String args[]) throws IOException
	{
		Hashtable person=new Hashtable();
		int n,i;
		String name, ph;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		System.out.print("Enter the number of person: ");
		n=Integer.parseInt(br.readLine());
		for(i=0;i<n;i++)
		{
			System.out.print("\nEnter the name of person: ");
			name=br.readLine();
			System.out.print("\nEnter phone number of person: ");
			ph=br.readLine();
			person.put(name,ph);
		}

		System.out.print("Details of person:"+person+"\n");

		System.out.print("Enter the details of person for searching:");
		name=br.readLine();
		if(person.containsKey(name))
		{
			System.out.print("\nPerson found\n");
			System.out.print("Name:"+name+"\nContact No."+person.get(name)+"\n");

		}

		else
		{
			System.out.print("\nNo person found");
		}
	}
}	
