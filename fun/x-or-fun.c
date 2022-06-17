#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int max(int array[], int size);
void printArray(int array[], int size);
void printBits(size_t const size, void const * const ptr);

int main(int argc, char * argv[]) {
   
   int array[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
   int arraySize = sizeof(array)/sizeof(int);
   printArray(array, arraySize);
   
   int maxValue = max(array, arraySize);
   int result = 0;
   printf("First loop...\n");
   for (int number = 1; number <= maxValue; number++) {
      result = result ^ number;
   }
   printf("Second loop...\n");
   for (int index = 0; index < arraySize; index++) {
      result = result ^ array[index];
   }
   printf("Missing number: %d\n", result);
   return EXIT_SUCCESS;
}

int max(int array[], int size) {
   int maxValue = INT_MIN;
   for (int i = 0; i < size; i++) {
      if (array[i] > maxValue) {
         maxValue = array[i];
      }
   }
   return maxValue;
}

void printArray(int array[], int size) {
   printf("Array contents: \n");
   for (int i = 0; i < size; i++) {
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
