#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printUsage(const char * binaryName);

// Prints a given number as a binary representation, assuming 64bit (8x8 bytes) environment.
int main(int argc, char * argv[]) {
   
   if (argc != 2) {
      printUsage(argv[0]);
      return EXIT_SUCCESS;
   }
   long long number = strtoll(argv[1], NULL, 10);
   if (number == 0 || number == LONG_MIN || number == LONG_MAX) {
      printf(" ** ERROR: could not convert input to long long integer.\n");
      printUsage(argv[0]);
      return EXIT_FAILURE;
   }
   printf("Show %lld in binary:\n", number);

   int counter, bit;
   for (counter = 63; counter >= 0; counter--)
   {
      bit = number >> counter;
      if (bit & 1) {
         printf("1");
      } else {
         printf("0");
      }
      if (counter % 4 == 0) {
         printf(" ");
      }
   }
   printf("\n");

   return EXIT_SUCCESS;
}

void printUsage(const char * binaryName) {
   printf("Usage: %s <number>\n", binaryName);
   printf("  Show the integer <number> in binary in systems with 64 bit integers.\n");
   printf("  Test also negative numbers to see how bits differ from positive integers.\n");
   printf("  Example run: %s 42\n", binaryName);
}
