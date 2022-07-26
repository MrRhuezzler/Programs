import java.util.*;

class Employee {
    String name;
    double salary;

    Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

}

public class Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Employee name: ");
        String name = sc.nextLine();

        System.out.println("Enter Employee salary: ");
        double salary = sc.nextDouble();

        Employee e = new Employee(name, salary);
        System.out.println("Employee name: " + e.getName());
        System.out.println("Employee salary: " + e.getSalary());
    }
}