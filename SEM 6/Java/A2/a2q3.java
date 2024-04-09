import java.sql.*;
import java.io.*;

class a2q3
{
	public static int getMark(int ta,int tc)
	{
		int marks;
		float per = ((float)ta/(float)tc)*100;
		System.out.println(per);
		if(per >= 90)
			marks=10;
		else if(per >= 80 && per <90)
			marks =9;
		else if(per >= 70 && per <80)
                        marks =8;
		else if(per >= 60 && per <70)
                        marks =7;
		else if(per >= 50 && per <60)
                        marks = 6;
		else if(per >= 40 && per <50)
                        marks =5;
		else if(per >= 30 && per <40)
                        marks =4;
		else if(per >= 20 && per <30)
                        marks =3;
		else if(per >= 10 && per <20)
                        marks =2;
		else
			marks =1;
		return marks;
	}
	public static void main(String args[]) throws IOException,ClassNotFoundException,SQLException
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		Connection con = null;
		Statement stmt = null;
		ResultSet rs = null;
		PreparedStatement ps=null;
		try
		{
			Class.forName("org.postgresql.Driver");
			con = DriverManager.getConnection("jdbc:postgresql://192.168.16.252/ty218531","ty218531","");
			if(con == null)
			{
				System.out.println("\nConnection Failed\n");
			}
			else
			{
				int total_attended,total_conducted,n,result,marks,max=0,roll=0;
				String sql,name , Class ,subject;
				System.out.println("\nConnection Successfully\n");
				
				//stmt = con.createStatement();
				System.out.println("\nEnter no. of students:\t");
				n = Integer.parseInt(br.readLine());
				for(int i = 0 ; i<n ; i++)
				{
					System.out.println("\nEnter the roll number of student u want to insert:\n");
                                        roll=Integer.parseInt(br.readLine());

					System.out.println("\nEnter the name of student u want to insert:\n");
					name = br.readLine();
					System.out.println("\nenter the class:\n");
					Class = br.readLine();
					System.out.println("\nEnter subject :\n");
					subject = br.readLine();
					System.out.println("\nenter total no. of attended classes:\n");
					total_attended = Integer.parseInt(br.readLine());
					if(max < total_attended)
						max = total_attended;
					sql = "insert into attendance values (?,?,?,?,?);";
				       	ps = con.prepareStatement(sql);
				       
				       	ps.setInt(1,roll);
				       	ps.setString(2,name);
				       	ps.setString(3,Class);
					ps.setString(4,subject);
					ps.setInt(5,total_attended);

					result = ps.executeUpdate();
					if(result == 1)
						System.out.println("\nData Inserted Successfully!\n");
				}
				System.out.println("\nEnter no. of lectures conducted \t");
				total_conducted = Integer.parseInt(br.readLine());
				while(total_conducted+1<= max)
				{
					System.out.println("\nConducted lectures can't be less than attended lecture \n enter conducted lectures again: ");
					total_conducted = Integer.parseInt(br.readLine());
				}
				stmt=con.createStatement();
				rs = stmt.executeQuery("select * from attendance");
				System.out.println("\n********Details of the Students******\n");
				while(rs.next())
				{
					System.out.println("\nRoll no. ="+rs.getInt(1)+"\t");
					System.out.println("\nName ="+rs.getString(2)+"\t");
					System.out.println("\nClass ="+rs.getString(3)+"\t");
					System.out.println("\nSubject ="+rs.getString(4)+"\t");
					System.out.println("\nTotal attended ="+rs.getInt(5)+"\t");

					marks = getMark(rs.getInt(5), total_conducted);
					System.out.println("Marks="+marks+"\n");
					System.out.println("\n___________________________\n");
				}
				rs.close();
				sql = "delete from attendance;";
				ps = con.prepareStatement(sql);
				result = ps.executeUpdate();
				if(result == 1)
                                                System.out.println("\nData deleted Successfully!\n");
				con.close();
                                

			}
		}
		catch (Exception e)
		{
			System.out.println(e);
		}
	}
}



				       
			       			       


