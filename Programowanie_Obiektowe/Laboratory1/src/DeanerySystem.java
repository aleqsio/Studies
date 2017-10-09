import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Aleksander on 03.10.2017.
 */
public class DeanerySystem {
        private static String weekdays[] = { "PN", "WT", "SR", "CZ", "PT", "SB", "ND"};
        private static weekDay weekdays2[] = { weekDay.PN, weekDay.WT, weekDay.SR, weekDay.CZ, weekDay.PT, weekDay.SB, weekDay.ND};
        public static void main(String[] args)
        {
                System.out.println("This is a main method");
                print(5);
                print("Napis");
                print(weekdays);
                print(weekdays2);
                read();
        }

        private static void read() {

                Scanner reader = new Scanner(System.in);  // Reading from System.in
                System.out.println("Enter a days combination separated by commas: ");
                String input = reader.nextLine();
                ArrayList<weekDay> days=new ArrayList<>();

                for (String i: input.split(",[ ]*")) {
                        try{
                                days.add(weekDay.valueOf(i));
                        }catch (IllegalArgumentException e)
                        {
                                System.out.println(i+" is not a valid day");
                        }
                }
                weekDay[] daysArr = new weekDay[days.size()];
                daysArr = days.toArray(daysArr);
                print(daysArr);
        }

        public static void print(int n)
        {
                System.out.println("Argument jest liczbą całkowitą "+n);
        }
        public static void print(String s)
        {
                System.out.println("Argument jest napisem "+s);
        }
        public static void print(String[] t){
                for (String day: t) {
                        System.out.println(getFullName(day));
                }
        }
        public static void print(weekDay[] t){
                for (weekDay day: t) {
                        System.out.println(getFullName(day));
                }
        }

        private static String getFullName(String key){
                switch(key){
                        case("PN"): return "Poniedziałek";
                        case("WT"): return "Wtorek";
                        case("SR"): return "Sroda";
                        case("CZ"): return "Czwartek";
                        case("PT"): return "Piątek";
                        case("SB"): return "Sobota";
                        case("ND"): return "Niedziela";
                }
                return "";
        }
        private static String getFullName(weekDay key){

                switch(key){
                        case PN: return "Poniedziałek";
                        case WT: return "Wtorek";
                        case SR: return "Sroda";
                        case CZ: return "Czwartek";
                        case PT: return "Piątek";
                        case SB: return "Sobota";
                        case ND: return "Niedziela";
                }
                return "";
        }


}
