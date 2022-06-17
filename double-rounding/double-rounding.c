#include <stdio.h>
#include <limits.h>

int main() {
   double number1 = 0.3137;
   double number2 = 0.2124;
   double result = number1 - number2;
   printf("%.20f - %.20f = %.20f\n", number1, number2, result);
   return 0;
}
