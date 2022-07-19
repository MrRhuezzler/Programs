import java.util.*;

public class Q9 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        System.out.printf("Max Iterations: ");
        int max = sc.nextInt();

        System.out.println("A\tB\tpower(A,B)");
        for(int i = 1, j = 2; i <= max; i++, j++) {
            System.out.println(i + "\t" + j + "\t" + Math.pow(i, j));
        }

    }

}