import java.text.*;
import java.net.*;
import java.io.*;

public class display {

    public static void main(String[] args) throws Exception{
        Socket s = new Socket("localhost",4000);
        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));
        // System.out.println("Client Ready");
        String responce = in.readLine();
        // SimpleDateFormat date1 = new SimpleDateFormat("d-m-y",responce);
        System.out.println("Date :" + responce);
        s.close();
    }    
}
