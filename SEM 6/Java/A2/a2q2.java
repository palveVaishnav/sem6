import java.io.*;
import java.sql.*;

class a2q2
{
	public static void main(String args[]) throws IOException, SQLException, ClassNotFoundException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Connection con=null;
		Statement stmt=null;
		ResultSet rs=null;
		PreparedStatement ps=null;
		PreparedStatement pst=null;
	try
	{
		Class.forName("org.postgresql.Driver");
		con=DriverManager.getConnection("jdbc:postgresql://192.168.16.252/ty218531","ty218531","");
		if(con==null)
		{
			System.out.println("\nConnection failed\n");
		}
		else
		{
			int n,ch,t_id,s_id,result,res;
			String sql,sql1, name,Class, subject, date,time;
			System.out.println("\nConnection established successfully");
			stmt=con.createStatement();
			do
			{
				   System.out.println("\nmenu \n1.add record\n2.display date wise lectures \n3.Display class wise timetable\n4.modify record of specific teacher\n5.exit\nEnter the choice :\t");
                                        ch = Integer.parseInt(br.readLine());
                                        if(ch==5)
                                                break;

                                        switch(ch)
                                        {
                                                case 1 : System.out.println("\nEnter the teacher_id u want to add");
                                                         t_id=Integer.parseInt(br.readLine());//t_id
                                                         System.out.println("\nEnter the name of teacher:\t");
                                                         name = br.readLine();//t_name
                                                         System.out.println("\nEnter the Subject id:\t");
                                                         s_id = Integer.parseInt(br.readLine());//s_id
                                                         System.out.println("\nEnter the subject name:\t");
                                                         subject = br.readLine();//s_name
                                                         System.out.println("\nEnter the date format(yyyy/mm/dd):\t");
                                                         date = br.readLine();//date
                                                         System.out.println("\nEnter the time format(hh:min):\t");
                                                         time = br.readLine();//time
                                                         System.out.println("\nEnter the class:\t");
                                                         Class = br.readLine();//class

                                                         sql = "insert into Teacher values (?,?);";
                                                         ps = con.prepareStatement(sql);
                                                         ps.setInt(1,t_id);
                                                         ps.setString(2,name);
                                                         res = ps.executeUpdate();

                                                         sql1 = "insert into workload values(?,?,?,?,?,?);";
                                                         pst = con.prepareStatement(sql1);
                                                         pst.setInt(1,s_id);
                                                         pst.setString(2,subject);
                                                         pst.setString(3,date);
                                                         pst.setString(4,time);
                                                         pst.setString(5,Class);
                                                         pst.setInt(6,t_id);
                                                         result = pst.executeUpdate();

							 if(res==1 && result==1)
							 {
								 System.out.println("\nData inserted successfully");
							 }
							 break;
						case 2:System.out.println("\nEnter the name of teacher: ");
						       name=br.readLine();
						       sql="select teacher_name, subject, date, time, class from teacher, workload  where teacher.teacher_id=workload.teacher_id and teacher_name=?";
						        ps = con.prepareStatement(sql);
                                                         ps.setString(1,name);
                                                         rs = ps.executeQuery();
                                                        while(rs.next())
                                                        {
                                                                System.out.println("teacher  = "+rs.getString(1)+"\t");
                                                                System.out.println("subject = "+rs.getString(2)+"\t");
                                                                System.out.println("date = "+rs.getString(3)+"\t");
                                                                System.out.println("Time = "+rs.getString(4)+"\t");
								 System.out.println("class = "+rs.getString(5)+"\t");

                                                                System.out.println("\n");
                                                        }
                                                        rs.close();
                                                        break;
						case 3 : System.out.println("\nEnter the class:\t");
                                                         Class = br.readLine();//class
                                                         sql = "select workload.date,workload.subject,workload.time from workload, teacher where workload.teacher_id = teacher.teacher_id and  workload.class=?";
                                                         ps = con.prepareStatement(sql);
                                                         ps.setString(1,Class);
                                                         rs = ps.executeQuery();
                                                        while(rs.next())
                                                        {
                                                                System.out.println("Date = "+rs.getString(1)+"\t");
                                                                //System.out.println("teacher name = "+rs.getSting(2)+"\t");
                                                                System.out.println("Subject = "+rs.getString(2)+"\t");
                                                                System.out.println("Time = "+rs.getString(3)+"\t");
                                                                System.out.println("\n");

                                                        }
                                                        rs.close();
                                                        break;
						  case 4 : System.out.println("\nEnter the teacher_id u want to update");
                                                         t_id=Integer.parseInt(br.readLine());//t_id
                                                         System.out.println("\nEnter the date format(yyyy/mm/dd):\t");
                                                         date = br.readLine();//date
                                                         System.out.println("\nEnter the time format(hh:min):\t");
                                                         time = br.readLine();//time
                                                         System.out.println("\nEnter the class:\t");
                                                         Class =br.readLine();//class
                                                         sql =  "update workload set date=?, time=?,class=? where teacher_id =?;";
                                                         ps = con.prepareStatement(sql);
                                                         ps.setString(1,date);
                                                         ps.setString(2,time);
                                                         ps.setString(3,Class);
                                                         ps.setInt(4,t_id);
                                                         res = ps.executeUpdate();
                                                         if(res == 1)
                                                                 System.out.println("\nData is updated successfully");
                                                         break;                                                                                  


                                                         default : System.out.println("wrong choice re-enter choice:");
                                                          ch = Integer.parseInt(br.readLine());
                                                          break;
                                        }
                                }while (ch!=5);
                        }
                }
                catch(Exception e)
                {
                        System.out.println(e);
                }
                finally
                {
                        stmt.close();
                        con.close();
                }
        }
}




