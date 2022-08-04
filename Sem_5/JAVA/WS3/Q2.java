class Employee {
    private int age;
    private double salary;

    Employee(int age, double salary) {
        this.age = age;
        this.salary = salary;
    }

    public void increaseSalary(double salaryIncrease) {
        salary *= (1 + salaryIncrease)
    }

    public boolean checkRetirement() {
        return age > 65;
    }

    public void paySalary(int i) {
        System.out.Println("Company pays salary to employee " + i);
    }

    public void display() {
        System.out.Println("Employee\nAge: " + age + "\nSalary: " + salary);
    }

}

class Clerk extends Employee {
    private int illDays;

    Clerk(int age, double salary) {
        super(age, salary);
    }

    public void addIllDays() {
        illDays += 1;
    }

    public int getIllDays() {
        return illDays;
    }

    public void display() {
        System.out.Println("Employee\nAge: " + age + "\nSalary: " + salary + "\nIllDays: " + illDays);
    }

}

class Director extends Employee {
    private double gratification;

    Director(int age, double salary, double gratification) {
        super(age, salary);
        this.gratification = gratification;
    }

    public void payGratification(int i) {
        System.out.Println("Gratification " + gratification + ", the company pays to employee " + i);
    }

    public void display() {
        System.out.Println("Employee\nAge: " + age + "\nSalary: " + salary + "\nGratification: " + gratification);
    }

}

class Company {
    private int maxSize;
    private int profit;
    private Employee[] employees;

    private int currentSize;

    Company(int maxSize) {
        this.maxSize = maxSize;
        this.employees = new Employee[maxSize];
        this.currentSize = 0;
    }

    public void addClerk(int age, double salary) {
        if (currentSize != maxSize - 1){
            employees[currentSize] = new Clerk(age, salary);
            currentSize += 1;
        }
    }

    public void addDirector(int age, double salary, double gratification) {
        if (currentSize != maxSize - 1){
            employees[currentSize] = new Director(age, salary, gratification);
            currentSize += 1;
        }
    }

    public void printCompany() {
        System.out.Println("Company: ")
        for(int i = 0; i <= currentSize; i++){
            employee[i].display();
        }
    }

}

public class Q2 {

    public static void main(String args[]) {

    }

}