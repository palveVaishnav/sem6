/*
    Create a hash table containg Person name and contact number.
    Display the details of the has table. Also search for specific person and display the contact number of
    that person.

 */ 

import java.util.*;

public class hashTable{
    public static void main(String[] args){
        // declare map
        Map<String , String> contactList = new HashMap<>();
        Scanner scan = new Scanner(System.in);
        String name = "";
        String contact = "";
        do{
            System.out.println("Enter Person Name :");
            name  = scan.nextLine();
            if(name.equals("-1")){
                System.out.println("Details accepting ternimated !!");
                break;
            }else{
                do{
                    System.out.println("Enter Contact Number : ");
                    contact = scan.nextLine();
                    if(contact.length() != 10){
                        System.out.println("Number is not Correct!! try again");
                    }
                }while(contact.length() != 10);

                contactList.put(name,contact);

            }
        }while(!name.equals("-1"));
        // details accepted
        System.out.println("The List is :\nName \tContact\n-------------");
        for(Map.Entry<String,String> entry : contactList.entrySet()){
            System.out.println(entry.getKey() +"\t"+entry.getValue());  
        }

        // searching 
        String searchName = "";

        do{
            System.out.println("Enter the name to Search");
            searchName = scan.nextLine();
            if(searchName.equals("-1")){
                System.out.println("Operation Terminated!!");
                break;
            }else{
                if(contactList.containsKey(searchName)){
                    System.out.println("Contact number of" + searchName + "is :" + contactList.get(searchName));
                }else{
                    System.out.println("Name Not in the list");
                }
            }
        }while(!searchName.equals("-1"));

        scan.close();
    }
}



