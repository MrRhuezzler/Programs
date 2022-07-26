import java.util.*;

class Account {

    private String owner;
    private double balance;
    private int accountNumber;

    public Account(String owner, double balance, int accountNumber) {
        this.owner = owner;
        this.balance = balance;
        this.accountNumber = accountNumber;
    }

    public Account(String owner, double balance) {
        // Generate a random 14-digit number for the account number
        this(owner, balance, (int) (Math.random() * 1000000000000L + 1000000000000L));
    }

    public Account(String owner) {
        // Generate a random 14-digit number for the account number
        this(owner, 0, (int) (Math.random() * 1000000000000L + 1000000000000L));
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Insufficient funds");
        } else {
            balance -= amount;
        }
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public double getBalance() {
        return balance;
    }

    public String toString() {
        return "Account owner: " + owner + "\nAccount number: " + accountNumber + "\nBalance: " + balance;
    }

}

public class Q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter owner: ");
        String owner = sc.nextLine();
        System.out.println("Enter balance: ");
        double balance = sc.nextDouble();
        System.out.println("Enter account number: ");
        int accountNumber = sc.nextInt();
        Account a = new Account(owner, balance, accountNumber);
        System.out.println(a);
        System.out.println("Enter amount: ");
        double amount = sc.nextDouble();
        a.withdraw(amount);
        System.out.println(a);
        System.out.println("Enter amount: ");
        amount = sc.nextDouble();
        a.deposit(amount);
        System.out.println(a);
    }
}