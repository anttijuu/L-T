#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Build: gcc -o xfun x-or-fun.c
// Run: execute xfun

int max(int array[], int size);
void printArray(int array[], int size);
void printBits(size_t const size, void const * const ptr);

bool showDetails = true; // Change to true to see details in output, false to hide them.

int main(int argc, char * argv[]) {
   
   int array[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
   int arraySize = sizeof(array)/sizeof(int);
	printf("\nThis tool finds a missing number from the array below,\n");
	printf("using XOR operator. The tool goes through two loops, first\n");
	printf("XORing the numbers from 1 to max value found in array,\n");
	printf("(10 in this example). Then second loop XORs the actual values\n");
	printf("in the array. The result will then contain the missing value.\n\n");

   printArray(array, arraySize);
   
   int maxValue = max(array, arraySize);
   int result = 0;
   printf("First loop...\n");
   for (int number = 1; number <= maxValue; number++) {
      if (showDetails) { printf("    "); printBits(sizeof(int), &result); }
      if (showDetails) { printf("XOR "); printBits(sizeof(int), &number); }
      result = result ^ number;
      if (showDetails) { printf("=   "); printBits(sizeof(int), &result); printf("----\n"); }
   }
   printf("Second loop...\n");
   for (int index = 0; index < arraySize; index++) {
      if (showDetails) { printf("    "); printBits(sizeof(int), &result); }
      if (showDetails) { printf("XOR "); printBits(sizeof(int), &array[index]); }
      result = result ^ array[index];
      if (showDetails) { printf("=   "); printBits(sizeof(int), &result); printf("----\n"); }
   }
   printf("Missing number is: %d\nAnd missing number in binary is: \n", result);
   printBits(sizeof(int), &result);
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
