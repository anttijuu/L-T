#include <stdio.h>
#include <limits.h>

int main() {
   int largeNumber = INT_MAX - 2;
   
   for (int counter = 0; counter < 5; counter++) {
      largeNumber++;
      printf("Large number: %d\n", largeNumber);
   }
   return 0;
}
