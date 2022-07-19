import java.util.*;
import java.text.*;

public class Q6 {

    public static void main(String args[]) {

        try {

            Scanner sc = new Scanner(System.in);
            System.out.println("Enter an integer: ");
            int num = sc.nextInt();
            System.out.println((char)num);

            double _27_times = 27 * num;
            System.out.println("The number tripled is: " + _27_times);

            double _by_27 = _27_times / 27;
            System.out.println("The number divided by 27 is: " + _by_27);

            DecimalFormat df = new DecimalFormat("#.##");
            
            System.out.println("Original Number: " + num);
            System.out.println("The number rounded is: " + df.format(_by_27));

        } catch (InputMismatchException e) {
            System.out.println("Invalid input");
        }

    }

}