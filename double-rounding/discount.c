#include <stdio.h>
#include <math.h>

int main() {
   double totalPrice = 1229.508;
   double discountLimit = 1500.0;
   double tax = 1.22;
   
   double fullPrice = totalPrice * tax;
   
   printf("full price is: %f\n", fullPrice);
   printf("discountLimit is: %f\n", discountLimit);
   // Not so good comparison here in use. Try using the one commented out.
   if (fullPrice > discountLimit) {
//   if (fullPrice > discountLimit || fabs(fullPrice - discountLimit) <= 0.01) {
      printf("Entitled for discount\n");
   } else {
      printf("Not entitled for discount\n");
   }
}
