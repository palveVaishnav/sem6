import java.io.*;
import java.net.*;
import java.util.*;

public class client2{
    public static void main(String[] args) throws Exception{
        // establish connection
        Socket s = new Socket("localhost",4000);

        // get the streams and readers ready.
        Scanner scan = new Scanner(System.in);
        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));
        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);

        System.out.println("Enter the file name : ");
        String fileName = scan.nextLine();
        out.println(fileName);
        String line;
        while(!(line = in.readLine()).equals("EndOfFile")){
            if(line.equals("File not Found")){
                System.out.println("Error :" + line);
                return;
            }
            System.out.println(line);
        }
    }
    
}
