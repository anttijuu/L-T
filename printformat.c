#include <stdlib.h>
#include <stdio.h>

void printBits(size_t const size, void const * const ptr);

int main() {
   int number = 42;
   
   printf("Number as int:   %d\n", number);
   printf("Number as uint:  %u\n", number);
   printf("Number as hex:   %x\n", number);
   printf("Number as oct:   %o\n", number);
   printf("Number as char:  %c\n", number);
   printf("Number as bits:  ");
   printBits(sizeof(int), &number);

   number = -1;
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
        }
    }
    puts("");
}


