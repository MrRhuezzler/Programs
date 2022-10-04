import java.util.*;

class SharedCounter extends Thread {

    static int counter = 0;

    void increment() {
        SharedCounter.counter++;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            increment();
            try {
                sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static int getCounter () {
        return SharedCounter.counter;
    }

}

public class Q3 {

    public static void main(String args[])  throws InterruptedException {

        ArrayList<SharedCounter> threads = new ArrayList<SharedCounter>();

        for (int i = 0; i < 10; i++) {
            SharedCounter sc = new SharedCounter();
            sc.start();
            threads.add(sc);
            System.out.println(SharedCounter.getCounter());
        }

        for (SharedCounter sc : threads) {
            sc.join();
        }

        System.out.println(SharedCounter.getCounter());

    }

}
