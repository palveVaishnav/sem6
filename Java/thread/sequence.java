// package Java.thread;
import java.util.*;
public class sequence {
    // two threads
    // waits for first to finish the execution

    public static void main(String[] args) {
        prime first = new prime();
        palindrome second = new palindrome();
        first.start();
        try {
            first.join();
            System.out.println("\nPrime number finished");
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("\npalindroem starting");
        second.start();
    }

}

class prime extends Thread {
    int flag;

    @Override
    public void run() {
        System.out.println("Prime numbers bteween 1 - 100 :");
        for (int i = 2; i < 101; i++) {
            if (isPrime(i)) {
                System.out.print(i + "\t");
            }
        }
    }

    public boolean isPrime(int num) {
        for (int i = 2; i < Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

class palindrome extends Thread {
    @Override
    public void run() {
        System.out.println("Palindrome number between 1 to 100 :");
        for (int i = 1; i < 101; i++) {
            if (isPalindrome(i)) {
                System.out.print(i + "\t");
            }
        }
    }

    public boolean isPalindrome(int num) {
        int rev = 0;
        int copy = num;
        while (copy > 0) {
            rev = rev * 10 + copy % 10;
            copy /= 10;
        }
        return rev == num;
    }
}
