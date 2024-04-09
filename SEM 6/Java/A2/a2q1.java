import java.sql.*;
import java.io.*;
import java.lang.*;
class a2q1 
{
	public static void main(String args[]) throws IOException, ClassNotFoundException, SQLException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Connection conn=null;
		Statement stmt=null;
		PreparedStatement ps=null;
		ResultSet rs=null;

		try
		{
			Class.forName("org.postgresql.Driver");
			conn=DriverManager.getConnection("jdbc:postgresql://192.168.56.1/demo","postgres","postgresql");
			if(conn==null)
			{
				System.out.println("\nConnection failed");
			}

			else
			{
				int ch, id, sal, result;
				String sql,name;
				System.out.println("connection successful");
		
			stmt=conn.createStatement();
			do
			{
				System.out.print("\n1)Enter details of employee\n2)Modify employee records\n3)Delete employee\n4)Search employee)\n5)view all recores\n6)Exit\nEnter the choice\n");
				ch=Integer.parseInt(br.readLine());
					if(ch==6)
						break;
				switch(ch)
				{
					case 1:System.out.print("\nEnter the ID of employee you want to insert: ");
					       id=Integer.parseInt(br.readLine());
					       System.out.println("\nEnter the name of employee: ");
					       name=br.readLine();
					       System.out.print("\nEnter the salary: ");
					       sal=Integer.parseInt(br.readLine());
					       sql="insert into employee values(?,?,?)";
					       ps=conn.prepareStatement(sql);
					       ps.setInt(1,id);
					       ps.setString(2,name);
					       ps.setInt(3,sal);
					       
					       result=ps.executeUpdate();
					       if(result==1)
					       {
						       System.out.println("\nData inserted successfully\n");
					       }
					       break;
					case 2:System.out.println("Enter the Id of the employee that you want to update: ");
					       id=Integer.parseInt(br.readLine());
					       System.out.print("\nEnter the name to be updated: ");
					       name=br.readLine();
					       System.out.print("Enter the salary to be updated: ");
					       sal=Integer.parseInt(br.readLine());
					       sql="UPDATE employee SET emp_name=?,salary=? where empid=?";
					       ps=conn.prepareStatement(sql);
					       ps.setString(1,name);
					       ps.setInt(2,sal);
					       ps.setInt(3,id);

					       result=ps.executeUpdate();
					       if(result==1)
						       System.out.print("\nData updated successfull\n");
					       break;
					case 3:System.out.print("\nEnter Id of employee that u want to delete: ");
					       id=Integer.parseInt(br.readLine());
					       sql="DELETE FROM employee WHERE empid=?";
					       ps=conn.prepareStatement(sql);
						  ps.setInt(1,id);

					       result=ps.executeUpdate();
					       if(result==1)
						       System.out.print("\nData deleted successfully");
					       break;
					case 4:System.out.print("\nEnter Id of employee that u want to search: ");
                                               id=Integer.parseInt(br.readLine());
                                               sql="SELECT * FROM employee where empid=?";
                                               ps=conn.prepareStatement(sql);
                                               ps.setInt(1,id);

                                                rs=ps.executeQuery();
                                               while(rs.next())
					       {

                                                       System.out.print("\nID:"+rs.getInt(1)+"\nName:"+rs.getString(2)+"\nSalary:"+rs.getInt(3)+"\n");
					       }
					       rs.close();
					       break;
					case 5: sql="SELECT * FROM employee";
                                                rs=stmt.executeQuery(sql);
                                               while(rs.next())
                                               {

                                                       System.out.print("\nID:"+rs.getInt(1)+"\tName:"+rs.getString(2)+"\tSalary:"+rs.getInt(3)+"\n");
                                               }
                                               rs.close();
                                               break;
					case 6:System.exit(0);

					defualt:System.out.print("\nWrong choice, plz enter correct choice");
					}
			}while(ch!=6);
		}

	}
	catch (Exception e)
	{
		System.out.println(e);
	}
	finally
	{
		stmt.close();
		conn.close();
	}	
}
}





