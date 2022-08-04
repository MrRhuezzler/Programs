import java.util.Scanner;

abstract class Book {
    private String title;
    private int dayTaken;
    private int overDueFee;

    Book(String title, int dayTaken, int overDueFee) {
        this.title = title;
        this.dayTaken = dayTaken;
        this.overDueFee = overDueFee;
    }

    public double computeDue(int dayReturned) {
        if (dayReturned - dayTaken > 0) {
            return overDueFee * (dayReturned - dayTaken);
        } else {
            return 0;
        }
    }

    public boolean isOverDue(int dayReturned) {
        return dayReturned - dayTaken > 0;
    }

}

class RegularBook extends Book {
    private String author;

    RegularBook(String title, int dayTaken, String author) {
        super(title, dayTaken, 1);
        this.author = author;
    }

}

class RefBook extends Book {

    RefBook(String title, int dayTaken) {
        super(title, dayTaken, 1);
    }

}

class AudioBook extends Book {
    private String author;

    AudioBook(String title, int dayTaken, String author) {
        super(title, dayTaken, 2);
        this.author = author;
    }

}

public class Q1 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Book[] books = new Book[n + n + n];
        for (int i = 0; i < n; i++) {
            String title = sc.next();
            int dayTaken = sc.nextInt();
            String author = sc.next();
            books[i] = new RegularBook(title, dayTaken, author);
        }
        for (int i = 0; i < n; i++) {
            String title = sc.next();
            int dayTaken = sc.nextInt();
            books[n + i] = new RefBook(title, dayTaken);
        }
        for (int i = 0; i < n; i++) {
            String title = sc.next();
            int dayTaken = sc.nextInt();
            String author = sc.next();
            books[n + n + i] = new AudioBook(title, dayTaken, author);
        }

        for (int i = 0; i < n + n + n; i++) {
            int dayReturned = sc.nextInt();
            int j = sc.nextInt();
            if (books[j].isOverDue(dayReturned)) {
                System.out.println(books[j].computeDue(dayReturned));
            } else {
                System.out.println(0);
            }
        }
    }
}