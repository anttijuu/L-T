#include <stdio.h>

int main() {

   int numberOfPersons = 0;
   int sumOfAges = 0;

   int proceed = 1;

   while (proceed) {
      printf("Continue average age counting, 0 = do not continue: ");
      scanf("%d", &proceed);
      if (!proceed) break;
      int age = 0;
      printf("Enter age: ");
      scanf("%d", &age);
      sumOfAges += age;
      numberOfPersons++;
   }
   // If giving 0 immediately to first question leaves numberOfPersons
   // to value zero. Dividing zero here results in undefined behaviour.
   // So the result could be anything.
	int medianAge = sumOfAges / numberOfPersons;
	printf("Median age is: %d\n", medianAge);
   return 0;
   // NB: compilers are developed and made less tolerant to errors like this.
   // Below this same code was built and executed on macOS Sonoma beta with Xcode 15 beta.
   // A floating point exception is generated to alert developers of division by zero:
   // > ./divbyzero
   // Continue average age counting, 0 = do not continue: 0
   // [1]    78791 floating point exception  ./divbyzero
}
