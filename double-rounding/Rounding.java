public class Rounding {
    public static void main(String [] args) {
        double number1 = 0.3137;
        double number2 = 0.2124;
        double result = number1 - number2;
        System.out.format("%.20f - %.20f = %.20f%n", number1, number2, result);
    }
}