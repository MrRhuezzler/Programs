import java.util.*;

public class Conversion {

    private static double convert(String from, String to, double value) {
        double result = 0;

        if(from.equals("fl.oz")) {
            if(to.equals("ml")) {
                result = value * 29.5735;
            } else {
                result = -1;
            }
        }

        if(from.equals("ml")) {
            if(to.equals("fl.oz")) {
                result = value / 29.5735;
            } else {
                result = -1;
            }
        }

        if(from.equals("gal")){
            if(to.equals("l")) {
                result = value * 3.78541;
            } else {
                result = -1;
            }
        }

        if(from.equals("l")) {
            if(to.equals("gal")) {
                result = value / 3.78541;
            } else {
                result = -1;
            }
        }

        return result;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Convert from: ");
        String from = sc.nextLine();
        System.out.println("Convert to: ");
        String to = sc.nextLine();
        System.out.println("Enter value: ");
        double value = sc.nextDouble();
        sc.close();

        double result = convert(from, to, value);
        if(result < 0) {
            System.out.println("Invalid Conversion");
        } else {
            System.out.println(result);
        }
    }

}