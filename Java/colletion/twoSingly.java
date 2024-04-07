// create two singly linked list , do not allow duplicate elements in one list

import java.util.*;

public class twoSingly {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        LinkedList<String> first = new LinkedList<>();
        String ele = "";
        System.out.println("Enter Elements for First Linked list :");
        do {
            ele = scan.nextLine();
            if (ele.equals("-1")) {
                System.out.println("Operation terminated !!");
                break;
            } else {
                if (first.contains(ele)) {
                    System.out.println("Element Already present !!");
                } else {
                    first.add(ele);
                }
            }
        } while (!ele.equals("-1"));

        LinkedList<String> second = new LinkedList<>();
        System.out.println("Enter Elements for second linkedList :");
        do {
            ele = scan.nextLine();
            if (ele.equals("-1")) {
                break;
            } else {
                if (second.contains(ele)) {
                    System.out.println("Already present");
                } else {
                    second.add(ele);
                }
            }
        } while (!ele.equals("-1"));

        System.out.println("First List " + first);
        System.out.println("Second list : " + second);

        // boolean contiueInput = true;
        boolean stop = false;
        while (!stop) {
            System.out.println("Enter Your Choise : ");
            System.out.println("1.Union\n2.Intersection\n3.Exit");
            int choise = scan.nextInt();
            scan.nextLine();
            switch (choise) {
                case 1:
                    LinkedList<String> union = new LinkedList<>(first);
                    union.addAll(second);
                    Set<String> unionSet = new  LinkedHashSet<>(union);
                    System.out.println("Union iis : " + unionSet);
                    break;
                case 2:
                    LinkedList<String> intersection = new LinkedList<>(first);
                    intersection.retainAll(second);
                    System.out.println("intersection is :" + intersection);
                    break;
                case 3:
                    stop = true;
                    break;
            }
        }

        scan.close();
    }
}