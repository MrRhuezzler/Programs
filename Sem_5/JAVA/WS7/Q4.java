import java.lang.*;
import java.util.Scanner;

public class Q4 {

    public static void main(String[] args) {
        int a, b, c;
        int[] d;

        Scanner sc = new Scanner(System.in);
        try {
            a = sc.nextInt();
            b = sc.nextInt();
            c = a / b;
            d = new int[a-2];
            System.out.println(c);
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException");
        } catch (NegativeArraySizeException e) {
            System.out.println("NegativeArraySizeException");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException");
        } catch (NumberFormatException e) {
            System.out.println("NumberFormatException");
        } catch (Exception e) {
            System.out.println("Exception");
        }

    }

}
