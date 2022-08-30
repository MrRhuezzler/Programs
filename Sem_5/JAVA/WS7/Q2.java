import java.lang.*;

class LessBalanceException extends Exception {
    public LessBalanceException(String s) {
        super(s);
    }
}

class Account {
    private double balance;

    Account(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public void deposit(double amount) {
        balance += amount;
    }

    public void withdraw(double amount) throws LessBalanceException {
        if (amount > balance) {
            throw new LessBalanceException("Insufficient Balance " + amount);
        } else {
            balance -= amount;
        }
    }

}

public class Q2 {

}