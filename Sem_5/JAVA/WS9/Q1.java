import java.util.*;

class FindDivisor extends Thread {

    private int N;
    private int result;

    public FindDivisor(int n) {
        this.N = n;
    }

    public void run() {
        for(int i = 1; i <= N; i++) {
            if(N % i == 0) {
                result++;
            }
        }
    }

    public int getNumOfDivisors() {
        return result;
    }

    public int getN() {
        return N;
    }

}

public class Q1 {

    public static void main(String args[]) throws InterruptedException {

        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
        ArrayList<FindDivisor> threads = new ArrayList<FindDivisor>();

        for(int i = 0; i <= 100000; i++) {
            FindDivisor fd = new FindDivisor(i);
            fd.start();
            threads.add(fd);
        }

        for(FindDivisor fd : threads) {
            fd.join();
        }

        int max = 0;
        ArrayList<Integer> maxDivisorN = new ArrayList<Integer>();
        for(FindDivisor fd : threads) {
            if(fd.getNumOfDivisors() > max) {
                max = fd.getNumOfDivisors();
                maxDivisorN.clear();
                maxDivisorN.add(fd.getN());
            } else if(fd.getNumOfDivisors() == max) {
                maxDivisorN.add(fd.getN());
            }
        }

        System.out.println(max);
        System.out.println(maxDivisorN);

    }

}
