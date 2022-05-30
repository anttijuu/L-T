#include <stdio.h>
#include <stdint.h>

void addWithUnsignedByte() {
   printf("Adding with unsigned bytes\n");
   uint8_t first = 79;
   uint8_t second = 99;
   uint8_t result = first + second;
   printf("First: %d + second: %d == %d\n", first, second, result);
}

void addWithSignedByte() {
   printf("Adding with signed bytes\n");
   int8_t first = 79;
   int8_t second = 99;
   int8_t result = first + second;
   printf("First: %d + second: %d == %d\n", first, second, result);
}

int main() {
   addWithUnsignedByte();
   addWithSignedByte();
   return 0;
}
