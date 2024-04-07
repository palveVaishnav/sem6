import java.io.*;
import java.util.*;
import java.net.*;


public class questions {
    public static void main(String [] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        Socket s = new Socket("localhost",4000);
        // inputs
        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));
        // outputs
        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);

        for(int i=0;i<10;i++){
            String que = in.readLine();
            System.out.println(que+ " \t:");
            String ans = scan.nextLine();
            out.println(ans);
        }
        s.close();
        scan.close();
    }
}
