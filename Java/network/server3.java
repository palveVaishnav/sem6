import java.io.*;
import java.net.*;
import java.util.*;

public class server3 {
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(4000);
        Socket s = ss.accept();

        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));

        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);

        String[] questions = {
            "First Question",
            "Second question",
            "Third Question",
            "Fourth question",
            "fifth question",
            "sixth question",
            "seventh question",
            "eight question",
            "ninth question",
            "tenth questiion",
            "eleven",
            "twelve",
            "thirteen",
            "fourteen",
            "fifteen"
        };

        ArrayList<String> ans = new ArrayList<>();

        for(int i=0;i<10;i++){
            int r = (int) (Math.random()*15);
            String question = questions[r];
            out.println(question);
            String a = in.readLine();
            ans.add(a);
        }

        System.out.println("Answers :" + ans);

        ss.close();
        s.close();
    }
}
