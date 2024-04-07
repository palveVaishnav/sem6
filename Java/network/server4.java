import java.io.*;
import java.net.*;
import java.util.*;

public class server4{
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(4000);
        Socket s = ss.accept();

        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));
        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);
        boolean prime = true;

        int number = Integer.parseInt(in.readLine());

        if(number <= 1){
            // prime = false;
            out.println(prime);
        }else{
            for(int i = 2;i<number;i++){
                if(number % i == 0){
                    prime = false;
                    // out.println(prime);
                    break;
                }
            }
        }
        out.println(prime);

    }
}
