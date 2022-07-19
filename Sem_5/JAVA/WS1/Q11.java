import java.util.*;

public class Q11 {

    private static boolean isPrime(int n) {
        if(n == 1) {
            return false;
        }
        for(int i = 2; i <= Math.sqrt(n); i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.printf("Start from : ");
        int from = sc.nextInt();
        System.out.printf("End at : ");
        int to = sc.nextInt();

        System.out.println("Prime numbers between " + from + " and " + to + " are: ");
        for(int i = from; i <= to; i++) {
            if(isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();

    }

}