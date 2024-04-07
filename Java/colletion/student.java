import java.util.*;

public class student {
    
    int rollno;
    String name;
    int age;

    public student(int rollno, String name, int age) {
        this.rollno = rollno;
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString(){
        return "Roll no : "+rollno+"\nName : "+name+"\nAge : "+age;
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        student s1 = new student(0,null,0);

        ArrayList<student> students = new ArrayList<student>();
        System.out.println("Enter Details : ");
        for (int i = 0; i < 2; i++) {
            System.out.println("Enter roll no : ");
            int rollno = scan.nextInt();
            scan.nextLine();
            System.out.println("Enter name :");
            String name = scan.nextLine();
            // scan.nextLine();
            System.out.println("Enter age : ");
            int age = scan.nextInt();
            scan.nextLine();
            student s = new student(rollno, name, age);
            students.add(s);
        }

        for(student s2 : students){
            System.out.println(s2);
        }

        scan.close();
    }

}
