#include <stdio.h>

int main() {

   int number = 1;

   printf("Number is: %d\n", number);
   
   number = number << 1;
   printf("Number is: %d\n", number);

   number = number << 1;
   printf("Number is: %d\n", number);

   number = number << 1;
   printf("Number is: %d\n", number);

   number = number >> 1;
   printf("Number is: %d\n", number);

   number = number >> 2;
   printf("Number is: %d\n", number);

   number = 3;
   number = number << 6;
   printf("Shifting 3 << 6\n");
   printf("3 << 6 is: %d\n", number);
   number = 3;
   for (int count = 0; count < 6; count++) {
      number = number << 1;
   }
   printf("3 shifted by 1 six times: %d\n", number); 
   number = 3;
   for (int count = 0; count < 3; count++) {
      number = number << 2;
   }
   printf("3 shifted by 2 three times: %d\n", number);
   return 0;
}
