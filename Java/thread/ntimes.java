// package Java.thread;
import java.util.*;

public class ntimes extends Thread{
    String message;

    public ntimes(String m){
        this.message = m;
    }

    @Override
    public void run(){
        System.out.println(this.message);
    }

    public static void main(String [] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter n:");
        int n = scan.nextInt();
        for(int i=0;i<n;i++){
            try{
                ntimes fy = new ntimes("Welcome to Fy");
                ntimes sy = new ntimes("Welcome to Sy");
                ntimes ty = new ntimes("Welcome to Ty");
                System.out.println("----------------");
                fy.start();
                sy.start();
                ty.start();
                // fy.sleep(10000);
                // sy.sleep(10000);
                ty.sleep(3000);
            }catch(Exception e){
                e.printStackTrace();
            }


        }
    }

    
}
