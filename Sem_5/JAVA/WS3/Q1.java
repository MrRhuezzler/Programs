class Account {
    private double balance;

    Account(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.Println("No sufficient funds");
        } else {
            balance -= amount;
        }
    }

}

class SavingAccount  extends Account {
    private static double defaultInterestRate = 2.5;
    public static void setDefaultInterestRate(double interestRate) {
        defaultInterestRate = interestRate;
    }

    private double interestRate;

    SavingAccount(double balance) {
        super(balance);
        interestRate = defaultInterestRate;
    }

    public void applyMonthlyInterest() {
        balance += (balance / interestRate);
    }

}

public class Q1 {
    public static void main(String args[]){

    }
}