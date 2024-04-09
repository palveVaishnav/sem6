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

    static class byName implements Comparator<student>{
        // @Override 
        public int compare(student a,student b){
            return a.name.compareTo(b.name);
        }
    }

    static class byAge implements Comparator<student>{
        public int compare(student a,student b){
            return (a.age-b.age);
        }
    }


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        // student s1 = new student(0,null,0);

        ArrayList<student> students = new ArrayList<student>();
        System.out.println("Enter Details : ");
        for (int i = 0; i < 3; i++) {
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
            System.out.println("--------------");
        }

        for(student s2 : students){
            System.out.println(s2);
        }

        System.out.println("By Name\n-----------");
        Collections.sort(students,new byName());
        for(student s2 : students){
            System.out.println(s2);
        }
        System.out.println("By Age :\n-----------");
        Collections.sort(students,new byAge());
        for(student g : students ){
            System.out.println(g);
        }
        scan.close();
    }

}
