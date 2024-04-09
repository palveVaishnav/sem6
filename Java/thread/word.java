import java.io.*;

public class word extends Thread {
    String toSearch;
    File f;
    boolean found;



    public word(String s,File f){
        this.toSearch = s;
        this.f = f;
        this.found = false;
    }
    @Override
    public void run(){
        searchWord(toSearch,f);
        if(!found){
            System.out.println("not Found");
        }
    }

    public void searchWord(String toSearch,File f){
        try{
            BufferedReader reader = new BufferedReader(new FileReader(f));
            String line;
            int linen=0;
            while( (line = reader.readLine()) != null ){
                linen++;
                if(line.contains(toSearch)){
                    System.out.println("File Name :" + f.getName() + "\nLine Number :" + linen );
                    found = true;
                }
            }
            reader.close();

        }catch(Exception e){
            e.printStackTrace();
        }
    }


    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("Incorrect number of arguments");
            return;
        }

        String toSearch = args[0];
        String pathString = args[1];
        File directory = new File(pathString);
        if(!directory.isDirectory()){
            System.out.println("Incorrect Path !!");
        }
        File[] files = directory.listFiles();
        if(files != null && files.length > 0){
            for(File f:files){
                if(f.isFile()){
                    // System.out.println("here------------");
                    word thread = new word(toSearch,f);
                    thread.start();
                }
            }
        }else{
            System.out.println("Empty Directory");
        }
    }

}
