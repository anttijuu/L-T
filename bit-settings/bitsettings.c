#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <ctype.h>

/*
 This program demonstrates how to use bits as on / off settings.
 Instead of having e.g. an array of bools. This way we can save
 memory, using only one byte of memory, instead of eight bools,
 that take eight bytes of memory. If the number of settings would
 be larger, this can lead to considerable memory savings, at least
 in embedded software development context.
 */

// Check if a setting is on or off.
bool isOn(uint8_t settings, int settingNumber);
// Change the setting from the settings either to on or off.
uint8_t change(uint8_t settings, int settingNumber, bool state);

// I/O
int readInt(void);
void flushInput(void);
void printSettings(uint8_t);
void printBits(size_t const, void const * const);

// Defining the settings values.
const uint8_t SETTING_EIGHT = 0b10000000; // 128 0x80
const uint8_t SETTING_SEVEN = 0b01000000; //  64 0x40
const uint8_t SETTING_SIX =   0b00100000; //  32 0x20
const uint8_t SETTING_FIVE =  0b00010000; //  16 0x10
const uint8_t SETTING_FOUR =  0b00001000; //   8 0x08
const uint8_t SETTING_THREE=  0b00000100; //   4 0x04
const uint8_t SETTING_TWO =   0b00000010; //   2 0x02
const uint8_t SETTING_ONE =   0b00000001; //   1 0x01

// Since working with only one byte, we have max eight settings available.
// If using uint16_t, we would have 16 different settings!
const int MAX_SETTINGS = 8;

// Put the settings to an array, so it is easy to look them up
// from the array by index 1...8 or actually 0...7 as we do in the codes.
const uint8_t lookUpTable[] = {
	SETTING_ONE,
	SETTING_TWO,
	SETTING_THREE,
	SETTING_FOUR,
	SETTING_FIVE,
	SETTING_SIX,
	SETTING_SEVEN,
	SETTING_EIGHT
};

int main() {
	
	// To show the difference in memory usage...
	bool arrayOfEightBools[8];
	uint8_t arrayOfEightBits;
	printf("Number of bits in eight bools : %lu\n", sizeof(arrayOfEightBools) * 8);
	printf("Number of bits in a byte      : %lu\n", sizeof(arrayOfEightBits) * 8);
	
	// Our eight settings can be stored here in one unsigned byte.
	uint8_t eightSettings = 0b00000000;
	
	// First print out the settings.
	printSettings(eightSettings);
	
	bool looping = true;
	do {
		int setting = 1;
		printf("\nWhich setting to switch on/off (1...8)?\n");
		printf("Entering anything else exits the app. > ");
		setting = readInt();
		if (setting >= 1 && setting <= MAX_SETTINGS) {
			// Get the old setting value...
			bool oldValue = isOn(eightSettings, setting);
			// ... and change it to opposite; not oldValue.
			eightSettings = change(eightSettings, setting, !oldValue);
			printSettings(eightSettings);
		} else {
			looping = false;
		}
	} while (looping);
	
	// After user input, we check if one or many setting bits are on or off.
	printf("\nIs any of the settings 6, 7 or 8 on?\n");
	uint8_t toCheck = SETTING_SIX | SETTING_SEVEN | SETTING_EIGHT;
	if ((eightSettings | (toCheck)) == toCheck) {
		printf("> Yes, one or more of these settings are on:\n");
	} else {
		printf("> No, none of those were on:\n");
	}
	printSettings(eightSettings);
	printf("\nAre both settings 1 and 2 on?\n");
	toCheck = SETTING_ONE | SETTING_TWO;
	if ((eightSettings & (toCheck)) == toCheck) {
		printf("Yes, both are on:\n");
	} else {
		printf("> No, none or only one of those were on.\n");
	}
	printSettings(eightSettings);

	return EXIT_SUCCESS;
}

// Checks if the given setting is on or off.
bool isOn(uint8_t settings, int settingNumber) {
	uint8_t toCheck = lookUpTable[settingNumber - 1];
	return (settings & toCheck);
}

// Changes the state of a given setting.
// This:  (state ? setting : 0x00)
// checks whether to set the setting to the value in setting,
// or set it to zero. This depends on the value of the boolean
// state parameter. Otherwise using binary AND (&), binary one's
// complement operator (~) which 'flips' the bits, and binary or
// operator (|).
//
// Learning exercise: Try out the operation below
// using samples, e.g. settings has bits like: 0000 0111 and then
// this function is called with values 3 and false:
// change(0b0000111, 3, false);
// So the third setting from the right which is currently 1, is set to 0.
// Do the operations on the left side of |, with binary bit flipping,
// binary AND and then the operation on the right side of | is
// binary ORred with left side. You should get the bits 0000 0011
// as the result.
uint8_t change(uint8_t settings, int settingNumber, bool state) {
	uint8_t toChange = lookUpTable[settingNumber - 1];
	return ((settings & ~toChange) | (state ? toChange : 0x00));
}

// Prints out the settings.
void printSettings(uint8_t settings) {
	printf("==> Settings are:\n");
	printf("Setting number: 8765 4321\n");
	printf("On or Off ----->");
	printBits(sizeof(settings), &settings);
}

// Prints bits of a thing as zeroes and ones, grouped in nibbles.
void printBits(size_t const size, void const * const ptr) {
	uint8_t *b = (uint8_t*) ptr;
	uint8_t byte;
	int i, j;
	
	for (i = size - 1; i >= 0; i--) {
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

// Reads one int from the keyboard and flushes the keyboard buffer.
int readInt(void) {
	int value = 0;
	scanf("%d", &value);
	flushInput();
	return value;
}

// Flushes the keyboard buffer.
void flushInput(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


