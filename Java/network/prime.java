import java.io.*;
import java.net.*;
import java.util.*;

public class prime{
    public static void main(String[] args) throws Exception{
        Scanner scan = new Scanner(System.in);
        Socket s = new Socket("localhost",4000);

        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));
        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);
        
        System.out.println("Enter the number :");
        int number = scan.nextInt();
        out.println(number);
        String isPrime = in.readLine();
        if(isPrime.equals("true")){
            System.out.println("The number is Prime");
        }else{
            System.out.println("Not Prime !!");
        }
    }
}
