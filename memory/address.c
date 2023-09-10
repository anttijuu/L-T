#include <stdio.h>

int main() {

   int number = 42;
   printf("Address of number:  %x\n", &number);
   printf("Value in address:   %d\n", number);
   int * pointerToInt = &number;
   printf("Address in pointer: %x\n", pointerToInt);
   printf("Address of pointer: %x\n", &pointerToInt);
   printf("Value in address:   %d\n", *pointerToInt);
   return 0;
}
