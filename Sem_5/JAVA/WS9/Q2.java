import java.util.*;
import java.lang.*;

class FindMax extends Thread {

    private int[] arr;
    private int max;

    public FindMax(int[] arr) {
        this.arr = arr;
        this.max = 0;
    }

    public void start() {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ", ");
        }
        System.out.print("\n");
        run();
    }

    public void run() {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }

    public int getMax() {
        return max;
    }

}

public class Q2 {

    public static int[] subArray(int[] array, int beg, int end) {
        return Arrays.copyOfRange(array, beg, end + 1);
    }

    public static void main(String args[]) throws InterruptedException {

        int[] arr = { 1, 2, 3, 4, 5 };
        ArrayList<FindMax> threads = new ArrayList<FindMax>();

        if (arr.length % 4 == 0) {
            for (int i = 0; i < 4; i++) {
                FindMax fm = new FindMax(subArray(arr, i * 4, (i + 1) * 4 - 1));
                fm.start();
                threads.add(fm);
            }
        } else {
            for (int i = 0; i < 4; i++) {
                FindMax fm;
                if (i == 3) {
                    fm = new FindMax(subArray(arr, i * 4, arr.length - 1));
                } else {
                    fm = new FindMax(subArray(arr, i * 4, (i + 1) * 4 - 1));
                }
                fm.start();
                threads.add(fm);
            }
        }

        for (FindMax fm : threads) {
            fm.join();
        }

        int max = 0;
        for (FindMax fm : threads) {
            if (fm.getMax() > max) {
                max = fm.getMax();
            }
        }

        System.out.println(max);

    }
}
