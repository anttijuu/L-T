# Unicode wide characters

C and C++ by default use narrow chars with 8 bytes and text is encoded either using ASCII or some default encoding of some specific system.

Usually this means that "special" characters like scandinavian characters do not work well. This is also OS dependent, and which tools, editors and fonts you have installed, influence on if you can see any special characters in various languages, like Finnish, Sapmi, Japanese or Russian, for example.

This demo code in `widechar.cpp` shows a C++ app printing out special characters using 8 bit chars with Finnish locale. This enables at least Scandinavian characters to display correctly.

Another function prints out wide characters, using `wchar_t` instead of `char`. The character array in this function contains, in addition to Finnish, also Sapmi, Russian and Japanese characters or symbols.

Whether they are displayed on your computer correctly after building the app, depends on your console and the ability of it and the operating system to display these. Probably on Windows this doesn't work without hassle.

On Unix computers and with terminal apps supporting Unicode, you will see the correct output with some characters from all these languages.

The accompanying `output.txt` shows how the program prints out wide Unicode characters propery. 
