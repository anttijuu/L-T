#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

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
   printf("size of int in bytes: %lu\n", sizeof(int));
   printf("Number as int:   %d\n", number);
   printf("Number as uint:  %u\n", number);
   printf("Number as hex:   %x\n", number);
   printf("Number as oct:   %o\n", number);
   printf("Number as char:  %c\n", number);
   printf("Number as bits:  ");
   printBits(sizeof(int), &number);

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
   printf("  Show the integer <number> in different radixes.\n");
   printf("  Test also negative numbers to see how output differ from positive integers.\n");
   printf("  Example run: %s 42\n", binaryName);
}
