import java.util.Scanner;

public class DivByZero {

   public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int sum = 0;
        int count = 0;
        int repeat = 1;
        while (repeat != 0) {
            System.out.println("Stop average counting (0 stops)?: ");
            repeat = scanner.nextInt();
            if (repeat == 0) {
                break;
            }
            System.out.println("Give an integer: ");
            int number = scanner.nextInt();
            sum += number;
            count++;
        }
        scanner.close();
        // In Java, this leads to java.lang.ArithmeticException: / by zero
        // if entering 0 to the first question.
        int average = sum / count;
        System.out.format("Average (rounded) is: %d", average);
    }
}
