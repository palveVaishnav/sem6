import java.net.*;
import java.io.*;


public class server2{
    public static void main(String[] args) throws Exception{
        ServerSocket ss = new ServerSocket(4000);
        System.out.println("Server Ready");
        Socket s = ss.accept();
        System.out.println("Connected");

        InputStream istream = s.getInputStream();
        BufferedReader in = new BufferedReader(new InputStreamReader(istream));

        OutputStream ostream = s.getOutputStream();
        PrintWriter out = new PrintWriter(ostream,true);

        String fileName = in.readLine();
        File file = new File(fileName);
        if(!file.isFile()){
            out.println("File not Found");
            // return;
        }else{
            out.println("Contents of the file :\n--------------------------------------");

            FileReader fileReader = new FileReader(file);
            BufferedReader reader = new BufferedReader(fileReader);
            String line;
            while((line = reader.readLine()) !=  null){
                out.println(line);
            }
            out.println("EndOfFile");
        }
        s.close();
        ss.close();
    }
}
