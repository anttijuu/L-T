#include <stdio.h>
#include <time.h>

int main() {
   int number = 10;
   int result_by_six;
   int result_by_thirty;
   long dummy = 0;
   clock_t start,end;
  
   // number << 1;
   
   start = clock();
   for (int index = 0; index < 10000000; index++) {
      //multipliers 4 ja 2
      result_by_six = (number << 2) + (number << 1);
      //multipliers 16, 8, 4, 2
      result_by_thirty = (number << 4) + (number << 3) + (number << 2) + (number << 1);
      dummy = result_by_six % index;
   }
   end = clock();
   printf("%d * 6: %d\n", number, result_by_six);
   printf("%d * 30: %d\n", number, result_by_thirty);
   printf("Time: %ld\n", end-start);

   start = clock();
   for (int index = 0; index < 10000000; index++) {
      //kertoimet 4 ja 2
      result_by_six = number * 6;
      //kertoimet 16, 8, 4, 2
      result_by_thirty = number * 30;
      dummy = result_by_thirty % index;
   }
   end = clock();
   printf("%d * 6: %d\n", number, result_by_six);
   printf("%d * 30: %d\n", number, result_by_thirty);
   printf("Time: %ld\n", end-start);

   return 0;
}
