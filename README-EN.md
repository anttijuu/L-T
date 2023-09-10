# Demos and samples

The demonstrations illustrate certain aspects of how computers work, from the programmer's viewpoint.

These are used in a basic course on computers. In the course **it is enought to study the source code**. Demos will be presented in the course teaching events. 

Contents:

* `asm-helloworld` -- a simple hello world app in assembly on macOS.
* `double-rounding` -- examples in C of situations where rounding errors of floating point numbers cause problems. Languages include C, Java and Swift.
* `divbyzero` -- division by zero error:
    * `divbyzero.c` -- an example in C, demonstrating division by zero. However, with most compilers, this appears to do *nothing special*, since the result of division by zero in C is "undefined behaviour" -- the program can do *anything* in this situation.
  * `DivByZero.java`, `DivByZero.swift`  -- examples how higher (than C) level programming languages Java and Swift create an exception or fatal error crashing the app, when attempting to divide by zero.
* `overflow` -- several examples of integer overflow happening in different languages.
  * `main.c` -- shows how integer overflow happens with C language.
  * `main.swift` -- the same as above but with Swift programming language. 
  * `overflow.c` -- overflow with eight bit numbers in C.
  * `overflow.swift` -- overflow with eight bit numbers in Swift.
* `printformat` -- printing out numbers in different number system values.
  * `numbinary.c` -- printing out long integers as bits.
  * `printformat.c` -- printing out an integer in different formats, char, unsigned, hex,...
* `shifting` -- examples of bit shifting operations on integers.
  * `shifting.c` -- a simple example of bit shifting.
  * `even-shift.c` -- shows how division and multiplication with even numbers can be done with bit shifting.
* `memory` -- demos related to memory.
  * `address.c` -- prints a value of a variable, the address of the variable, the address of a pointer pointing to the variable, etc.
  * `endian.cpp` -- prints out bytes in memory, where you can see if a computer is little or big endian. Includes printouts from two Macs, another in Intel x86 PC architecture, another from Apple Silicon aarch64 architecture.
  * `stackoverflow.c` -- demonstrates how stack overflow happens when calling recursive functions with large local variables. By editing the code you can make the stack overflow disappear by using heap memory instead of stack.  
* `fun` -- fun examples :)
  * `Planets.swift` -- prints out the symbols of the planets as Unicode characters. Pluto included.
  * `spooky.swift` -- an example on how modern programming languages allow using almost any Unicode symbols in variable and function names, as well as values -- even emojis!
  * `x-or-fun.c` -- an example in C on how xor operation can be used to solve a problem related to arrays; how to find one missing number in a series of numbers in an array.
  * `x-or-fun.swift` -- an example in Swift on how xor operation can be used to solve a problem related array.
* `gates-in-c` -- demonstrates how to implement gates programmatically, related to Exercise 3.
* `bit-settings` -- an example of *binary* AND and OR operations and how to use them in bit manipulation. The example manages eight on/off settings with one byte. Also demonstrates how one can convert a capital ASCII character to lowercase by flipping one bit. More information in the code comments.
* `unicode-char` -- an example about how special characters, like Scandinavian, Sapmi, Russian and Japanese chars do not display correctly, if using narrow 8 bit characters. When using wide chars, they can be printed correctly. Although this also depends on your computer; how well it supports Unicode at terminal window. Usually Windows is not too good at this. Also the terminal window must be configured to use Unicode and the font used in displaying text must contain the necessary glyphs to show these special characters, outside the more usual ASCII, Latin 1 etc. This demo is different from the rest in that it requires C++.

## Compiling and executing

If you wish to try out compiling and executing the demos yourself, instructions can be found below.

Compiling and running the demos require that you install the necessary compilers etc. for the languages:

* C: either GCC or clang compiler: esim https://gcc.gnu.org
* Java: Java Development Kit (JDK): https://jdk.java.net/18/
* Swift: Swift tools: macOS: install Xcode, others: https://www.swift.org/download/

Usually installing any software development kit installs or provides easy ways to install compilers. Ask more from teachers if needed.

### Compiling a C program from the terminal:

If you are on Windows, the program binary name is typically e.g. `app.exe`, so add the .exe to the command below.

```console
gcc file.c -o app
```

After which, execute the "app" file from the terminal.

Alternatively, you may use the clang compiler. In this case, just replace the command `gcc` with the command `clang`. 

### Compiling a Java program from the terminal:

```console
javac File.java
```
And execute it:

```console
java File
```

### Compiling a Swift program from the terminal:

```console
swiftc file.swift -o app
```

After which, execute the "app" file from the terminal.

