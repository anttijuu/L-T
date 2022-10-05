// From standard C
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// From standard C++
#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>


void printBits(size_t const size, void const * const ptr);
void printASCII(void);
void printWideChars(void);

int main() {
	
	// Needed to get scandinavian chars aligned properly in printing shortest path.
	std::setlocale(LC_ALL, "fi_FI.UTF-8");
	std::locale loc("fi_FI.UTF-8");
	std::wcout.imbue(loc);
	
	int number = 42;
	
	printf("Number as int:   %d\n", number);
	printf("Number as uint:  %u\n", number);
	printf("Number as hex:   %x\n", number);
	printf("Number as oct:   %o\n", number);
	printf("Number as char:  %c\n", number);
	printf("Address of number: %x\n", &number);
	
	printf("Number as bits:  ");
	printBits(sizeof(int), &number);
	
	number = -1;
	
	printf("Number as int:   %d\n", number);
	printf("Number as uint:  %u\n", number);
	printf("Number as hex:   %x\n", number);
	printf("Number as oct:   %o\n", number);
	printf("Number as char:  %c\n", number);
	printf("Address of number: %x\n", &number);
	printf("Number as bits:  ");
	printBits(sizeof(int), &number);
	
	printf("\n-=* ASCII chars and codes with 7 bit ascii encoding *=-\n");
	printASCII();
	printf("\n-=* ASCII chars and codes with wide char 16 bit encoding *=-\n");
	printWideChars();
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


void printASCII(void) {
	char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWZYZÅÄÖØÆabcdefghijklmnopqrstuvwzyzåäöøæ1234567890исполнительныйGuovddášbellodagaコースワークとして提供されるすべて";
	
	for (int index = 0; index < strlen(chars); index++) {
		printf("char: %c -- code: %d\n", chars[index], chars[index]);
	}
}

void printWideChars(void) {
	wchar_t chars[] = L"ABCDEFGHIJKLMNOPQRSTUVWZYZÅÄÖØÆabcdefghijklmnopqrstuvwzyzåäöøæ1234567890исполнительныйGuovddášbellodagaコースワークとして提供されるすべて";
	
	for (int index = 0; index < wcslen(chars); index++) {
		std::wcout << "char: " << chars[index] << " -- code: " << (int)chars[index] << std::endl;
	}
}
