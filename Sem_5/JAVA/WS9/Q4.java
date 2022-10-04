import java.util.ArrayList;

class eOdd extends Thread {

    private int start = 0;
    private double result = 0;

    public eOdd(int start) {
        this.start = start;
    }

    public void run() {
        for (int i = start; i < start + 2; i++) {
            result += 1 / factorial(2 * i + 1);
            // System.out.println((2 * i + 1) + " " + factorial(2 * i + 1));
        }
    }

    private int factorial(int n) {
        int fac = 1;
        for (int i = 1; i <= n; i++) {
            fac *= i;
        }
        return fac;
    }

    public double getResult() {
        return result;
    }

}

class eEven extends Thread {

    private int start;
    private double result = 0;

    public eEven(int start) {
        this.start = start;
    }

    public void run() {
        for (int i = start; i < start + 2; i++) {
            result += 1 / factorial(2 * i);
        }
    }

    private int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public double getResult() {
        return result;
    }
}

public class Q4 {

    public static void main(String args[]) {

        ArrayList<Thread> threads = new ArrayList<Thread>();
        
        for(int i = 1; i <= 8; i+=1) {
            eOdd odd = new eOdd(i);
            eEven even = new eEven(i);
            odd.start();
            even.start();
            threads.add(odd);
            threads.add(even);
        }

        for(Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        double result = 0;
        for(Thread t : threads) {
            if(t instanceof eOdd) {
                result += ((eOdd) t).getResult();
            } else {
                result += ((eEven) t).getResult();
            }
        }

        System.out.println(result);
    }

}
