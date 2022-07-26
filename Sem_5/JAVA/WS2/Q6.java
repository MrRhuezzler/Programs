import java.util.*;

class Triangle {

    double a, b, c;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    Triangle(){
        this.a = 0;
        this.b = 0;
        this.c = 0;
    }

    public boolean isTriangle(){
        if (a + b > c && a + c > b && b + c > a) {
            return true;
        } else {
            return false;
        }
    }

    public boolean isEquilateral(){
        if(isTriangle()){
            if (a == b && b == c) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    public boolean isIsosceles(){
        if(isTriangle()){
            if (a == b || a == c || b == c) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    public boolean isRight(){
        if(isTriangle()){
            if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    public boolean isScalene(){
        if(isTriangle()){
            if (a != b && a != c && b != c) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    public boolean isEqual(Triangle other){
        if(isTriangle() && other.isTriangle()){
            if (a == other.a && b == other.b && c == other.c) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }

    public double getArea() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }
    
    public double getPerimeter() {
        return a + b + c;
    }
}

public class Q6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a: ");
        double a = sc.nextDouble();
        System.out.println("Enter b: ");
        double b = sc.nextDouble();
        System.out.println("Enter c: ");
        double c = sc.nextDouble();
        Triangle t = new Triangle(a, b, c);
        if (t.isTriangle()) {
            System.out.println("The triangle is valid");
            if (t.isEquilateral()) {
                System.out.println("The triangle is equilateral");
            } else if (t.isIsosceles()) {
                System.out.println("The triangle is isosceles");
            } else if (t.isRight()) {
                System.out.println("The triangle is right");
            } else if (t.isScalene()) {
                System.out.println("The triangle is scalene");
            }
            System.out.println("Area: " + t.getArea());
            System.out.println("Perimeter: " + t.getPerimeter());
        } else {
            System.out.println("The triangle is invalid");
        }
    }
}