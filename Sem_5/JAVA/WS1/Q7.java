import java.util.*;

public class Q7 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter date (mon day year): ");
        int mon = sc.nextInt();
        int day = sc.nextInt();
        int year = sc.nextInt();

        Dictionary<Integer, Integer> monthDays = new Hashtable<Integer, Integer>();
        monthDays.put(1, 31);
        monthDays.put(2, 28);
        monthDays.put(3, 31);
        monthDays.put(4, 30);
        monthDays.put(5, 31);
        monthDays.put(6, 30);
        monthDays.put(7, 31);
        monthDays.put(8, 31);
        monthDays.put(9, 30);
        monthDays.put(10, 31);
        monthDays.put(11, 30);
        monthDays.put(12, 31);

        if (year % 4 == 0) {
            monthDays.put(2, 29);
        }

        if (mon < 1 || mon > 12) {
            System.out.println("Invalid month");
        } else if (day < 1 || day > monthDays.get(mon)) {
            System.out.println("Invalid day");
        } else {
            System.out.println("It is a valid date");
        }

    }

}