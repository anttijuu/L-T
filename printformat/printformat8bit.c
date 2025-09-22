#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

void printBits(size_t const size, void const * const ptr);
void printUsage(const char * binaryName);


int main(int argc, char * argv[]) {

   if (argc != 2) {
      printUsage(argv[0]);
      return EXIT_SUCCESS;
   }
   int number = atoi(argv[1]);
   if (number == 0 || number == INT_MIN || number == INT_MAX) {
      printf(" ** ERROR: could not convert input to integer.\n");
      printUsage(argv[0]);
      return EXIT_FAILURE;
   }
	if (number > 127 || number < -128) {
		printf("Range of values for signed 8 bit number is -128...127\n");
		printUsage(argv[0]);
		return EXIT_FAILURE;
	}
	int8_t negative = -116;
	int8_t positive = negative & 0x7F;
	printf("First: How binary AND with 0x7F flips the most significant bit from 1 to 0\n");
	printf("Operation to execute:\n  int8_t negative = -116;\n  int8_t positive = negative & 0x7F;\n");
	printf("Negative value %hd became positive: %hd\n\n", negative, positive);
	
	printf("Input was: %d\n", number);
	int8_t actualValue = number;
   printf("- Size of int in bytes: %lu\n", sizeof(int8_t));
   printf("- Number as int:   %hd\n", actualValue);
   printf("- Number as uint:  %hhu\n", actualValue);
   printf("- Number as hex:   %hx\n", actualValue);
   printf("- Number as oct:   %hho\n", actualValue);
   printf("- Number as char:  %c\n", actualValue);
   printf("- Number as bits:  ");
   printBits(sizeof(actualValue), &actualValue);

   return EXIT_SUCCESS;
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

void printUsage(const char * binaryName) {
   printf("Usage: %s <number>\n", binaryName);
   printf("  Show the 8 bit signed <number> in different radixes.\n");
   printf("  Test also negative numbers to see how output differ from positive integers.\n");
   printf("  Example run: %s 42\n", binaryName);
}
