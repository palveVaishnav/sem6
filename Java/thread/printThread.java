import java.util.*;
public class printThread {
    public static void main(String [] args){
        int len = args.length;
        if(len != 2 ){
            System.out.println("Invalid arguments");
            return;
        }
        int n = Integer.parseInt(args[0]);
        String text = args[1];
        System.out.println(text);
        for(int i =0;i<3;i++){
            PrintText thread = new PrintText(n,text);
            thread.start();
        }

    }    
}

class PrintText extends Thread{
    int n;
    String text;
    public PrintText(int n,String text){
        this.n = n;
        this.text = text;
    }
    @Override 
    public void run(){
        System.out.println(this.text);
    }
}










