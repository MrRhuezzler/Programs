import java.util.*;

class Car {

    // In miles per gallon
    double efficiency;

    // In gallons
    double fuel;

    Car(double efficiency) {
        this.efficiency = efficiency;
        this.fuel = 0;
    }

    public void drive(double distance) {
        double needed = distance / efficiency;
        if (needed > fuel) {
            System.out.println("You can't drive " + distance + " miles");
        } else {
            fuel -= needed;
            System.out.println("You drove " + distance + " miles");
        }
    }

    public void tank(double amount) {
        fuel += amount;
    }

    public double getFuel() {
        return fuel;
    }

}

public class Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter efficiency: ");
        double efficiency = sc.nextDouble();
        Car c = new Car(efficiency);
        System.out.println("Enter fuel: ");
        double fuel = sc.nextDouble();
        c.tank(fuel);
        System.out.println("Enter distance: ");
        double distance = sc.nextDouble();
        c.drive(distance);
        System.out.println("Fuel left: " + c.getFuel());
    }
}
