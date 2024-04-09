import java.io.*;
import java.net.*;
import java.sql.*;

class program4_Server
{
  public static void main(String args[])throws Exception
  {
   String str1,str2="",line;

   ServerSocket ss = new ServerSocket(2101);

   System.out.println("Server is Running.....");

   Socket s = ss.accept();

   System.out.println("Connection is Successfully established...");

   PrintStream ps = new PrintStream(s.getOutputStream());

   BufferedReader br2 = new BufferedReader(new InputStreamReader(s.getInputStream()));

   BufferedReader br1 = new BufferedReader(new InputStreamReader(System.in));

     	str1= br2.readLine();
	int str3 = Integer.parseInt(str1);
	
	int i ,m=0,flag=0,temp=3;
	m=str3/2;
 	if(str3==0 || str3==1){
		temp=0;
	}
	else{
	for(i=2;i<=m;i++)
	{
	temp=0;
	flag=1;
	break;
	}
	
	}
	if(flag==0)
	{
	temp=1;
	}
	ps.println(temp);
	

  /* Connection conn = null;
        Statement stat = null;
        ResultSet res = null;
        try
        {
        Class.forName("org.postgresql.Driver");
        conn = DriverManager.getConnection("jdbc:postgresql://192.168.16.1/ty8801","ty8801","");
        if(conn==null)
        {
                System.out.println("Connection failed");
        }
   int i=1;
   int score=0;
   while(i!=10)
   {
    int random=(int)(Math.random()*(10-1)+1);
    String str,st,result="";

    res = stat.executeQuery("select * from mcq where mcq_id = "+random);
    if(res.next())
    {
     str=res.getString(2);
     st=res.getString(3);
     result=res.getString(4);              
    ps.println(str);
    ps.println(st);
    }
    String res1=br2.readLine();
    if(res1.equals(result))
    {
     score=score+1;
    }
    i++;
   }
   ps.println(score);
   */
   ss.close();
   s.close();
   ps.close();
   br1.close();
   br2.close();
  }
}
