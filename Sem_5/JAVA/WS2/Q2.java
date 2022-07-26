import java.util.*;

class Student {
    
    String name;
    ArrayList<double> quizzes;

    Student(String name) {
        this.name = name;
        this.quizzes = new ArrayList<double>();
    }

    public String getName() {
        return name;
    }

    public addQuiz(double score) {
        quizzes.add(score);
    }

    public double getTotalScore() {
        double total = 0;
        for (double quiz : quizzes) {
            total += quiz;
        }
        return total;
    }

    public double getAverageScore() {
        return getTotalScore() / (double)quizzes.size();
    }

}

public class Q2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Student name: ");
        String name = sc.nextLine();

        Student s = new Student(name);
        System.out.println("Enter Student quizzes scores: ");
        while (sc.hasNextDouble()) {
            s.addQuiz(sc.nextDouble());
        }

        System.out.println("Student name: " + s.getName());
        System.out.println("Student total score: " + s.getTotalScore());
        System.out.println("Student average score: " + s.getAverageScore());
    }
}