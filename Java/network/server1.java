import java.net.*;
import java.util.*;
import java.io.*;

public class server1 {
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(4000);
        System.out.println("Server Ready !!");
        Socket s = ss.accept();
        System.out.println("Connected");
        
        OutputStream stream = s.getOutputStream();
        PrintWriter out = new PrintWriter(stream,true);
        Date d = new Date();
        out.println(d);
        s.close();
    }
}

