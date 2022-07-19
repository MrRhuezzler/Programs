import java.util.*;

public class Q10 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int matrix[][] = new int[5][4];

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[i][j] = rand.nextInt(10);
            }
        }

        System.out.println("Matrix (Before Column sum): ");
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 4; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

        for(int i = 0; i < 4; i++) {
            int sum = 0;
            for(int j = 0; j < 5; j++) {
                sum += matrix[j][i];
            }
            matrix[4][i] = sum;
        }
        System.out.println();
        System.out.println("Matrix (After Column sum): ");
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 4; j++) {
                System.out.print(matrix[i][j] + "\t");
            }
            System.out.println();
        }

    }

}