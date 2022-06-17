#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printBits(size_t const size, void const * const ptr);

int main(int argc, char * argv[]) {

   int [] array = {1, 2, 3, 4, 6, 7, 8, 9, 10};
   printArray(array);

   int maxValue = max(array);
   int result = 0;

   return EXIT_SUCCESS;
}

int max(int [] array) {
   int max = INT_MIN;
   for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
      if (array[i] > max {
         max = array[i];
      }
          }
          return max;
          }

          void printArray(int [] array) {
         for (int i = 0; i < sizeof(array)/sizeof(int); i++) {
            printf("%d, ", array[i]);
         }
         printf("\n");
      }

          void printBits(size_t const size, void const * const ptr)
          {
         unsigned char *b = (unsigned char*) ptr;
         unsigned char byte;
         int i, j;

         for (i = size-1; i >= 0; i--) {
            for (j = 7; j >= 0; j--) {
               byte = (b[i] >> j) & 1;
               printf("%u", byte);
               if (j % 4 == 0) {
                  printf(" ");
               }
            }
         }
         puts("");
      }
