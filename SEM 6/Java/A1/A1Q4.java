import java.io.*;
import java.util.*;
class student
{
	int roll,age;
	String Name;
	student(int r, int a, String n)
	{
		roll=r;
		age=a;
		Name=n;
	}
}


class SortByName implements Comparator<student>
{
	public int compare(student a, student b)
	{
		return a.Name.compareTo(b.Name);
	}
}

class SortByAge implements Comparator<student>
{
	public int compare(student a, student b)
	{
		return a.age-b.age;
	}
}

public class A1Q4
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		ArrayList<student> stud= new ArrayList<student>();
		int r,a;
		String nm;
		System.out.print("\nEnter number of students: ");
		int n=Integer.parseInt(br.readLine());
		for(int i=0;i<n;i++)
		{
			System.out.println("\nEnter roll no: ");
			r=Integer.parseInt(br.readLine());
			System.out.println("\nEnter Age: ");
			a=Integer.parseInt(br.readLine());
			System.out.println("\nEnter Name: ");
			nm=br.readLine();
			stud.add(new student(r,a,nm));
		}

		System.out.print("\nSorted By name:\n");
		System.out.print("Roll no.\tName\tAge\n");
		Collections.sort(stud,new SortByName());
		for(int i=0;i<n;i++)
		{
			System.out.println(stud.get(i).roll+"\t\t"+stud.get(i).Name+"\t"+stud.get(i).age);
		}

		 System.out.print("\nSorted By name:\n");
		 System.out.println("Roll no.\tName\tAge\n");

                Collections.sort(stud,new SortByAge());
                for(int i=0;i<n;i++)
                {
    		        System.out.println(stud.get(i).roll+"\t\t"+stud.get(i).Name+"\t"+stud.get(i).age);

                }

	}
}




