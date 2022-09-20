#include <stdio.h>

int main() {

   int numberOfPersons = 0;
   int sumOfAges = 1;

   int proceed = 1;

   while (proceed) {
      printf("Lasketaanko keskiarvoja, 0 = ei lasketa: ");
      scanf("%d", &proceed);
      if (!proceed) break;
      int age = 0;
      printf("Anna ika: ");
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
}
