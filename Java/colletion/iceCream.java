import java.util.*;


public class iceCream {
        // accept the flavours in set
        // connvert the set to hash map
        public static void main(String[] args){
                
                Scanner scan = new Scanner(System.in);
                List<String> flavours = new ArrayList<>();
                String flavour = "";
                // Set<String> flavorsSet = new HashSet<>();

                System.out.println("Enter the Flavour : ");
                do{
                        flavour = scan.nextLine();
                        if(!flavour.equals("-1") && !flavours.contains(flavour)){
                                flavours.add(flavour);
                        }else if(flavour.equals("-1")){
                                System.out.println("Operatin terminating");
                                break;
                        }else if(flavours.contains(flavour)){
                                System.out.println("Already Exist !!!");
                        }

                }while(!flavour.equals("-1"));

                String search = "";
                do{
                        System.out.println("Enter Flavour to search : ");
                        search = scan.nextLine();
                        if(flavours.contains(search)){
                                System.out.println("The flavour is present !");
                        }else{
                                System.out.println("not present");
                        }
                }while(!search.equals("-1"));
                
                List<String> sortedFlavour = new ArrayList<>(flavours);
                System.out.println("UnSorted List : "+ sortedFlavour);
                Collections.sort(sortedFlavour);
                System.out.println("Sorted List : "+ sortedFlavour);

                // adding prize 
                Map<String,Double> withPrize = new HashMap<>();
                
                for(String f: flavours){
                        System.out.println("Enter Prize for " + f + " :");
                        double prize = scan.nextDouble();
                        withPrize.put(f,prize);
                }
                 System.out.println(withPrize);

        }


}
