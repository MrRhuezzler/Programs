import java.lang.*;
import java.text.SimpleDateFormat;
import java.time.YearMonth;
import java.util.Date;
import java.util.Scanner;

class MonthOutOfRangeException extends Exception {
    public MonthOutOfRangeException(String s) {
        super(s);
    }
}

class DayOutOfRangeException extends Exception {
    public DayOutOfRangeException(String s) {
        super(s);
    }
}

public class Q5 {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

        int a_month = sc.nextInt();
        int a_day = sc.nextInt();
        int a_year = sc.nextInt();

        int d_month = sc.nextInt();
        int d_day = sc.nextInt();
        int d_year = sc.nextInt();

        try {

            if (a_month < 1 || a_month > 12) {
                throw new MonthOutOfRangeException("Arrival Month out of range");
            }

            if (d_month < 1 || d_month > 12) {
                throw new DayOutOfRangeException("Departure Day out of range");
            }

            YearMonth yearMonthObject = YearMonth.of(a_year, a_month);
            if (!yearMonthObject.isValidDay(a_day)) {
                throw new DayOutOfRangeException("Invalid Arrival day");
            }

            yearMonthObject = YearMonth.of(d_year, d_month);
            if (!yearMonthObject.isValidDay(d_day)) {
                throw new DayOutOfRangeException("Invalid Departure date");
            }

        } catch (MonthOutOfRangeException e) {
            System.out.println(e.getMessage());
        } catch (DayOutOfRangeException e) {
            System.out.println(e.getMessage());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }

}
