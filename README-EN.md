# Demos and samples

The demonstrations illustrate certain aspects of how computers work, from the programmer's viewpoint.

These are used in a basic course on computers. In the course **it is enought to study the source code**. Demos will be presented in the course teaching events. 

Contents:

* `asm-helloworld` -- a simple hello world app in assembly on macOS.
* `double-rounding` -- examples in C of situations where rounding errors of floating point numbers cause problems. Languages include C, Java and Swift.
* `divbyzero` -- division by zero error:
  * `divbyzero.c` -- C example, shows how app crashes if number is divided by zero.
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
* `fun` -- fun examples :)
  * `spooky.swift` -- an example on how modern programming languages allow using almost any Unicode symbols in variable and function names, as well as values -- even emojis!
  * `x-or-fun.c` -- an example in C on how xor operation can be used to solve a problem related to arrays; how to find one missing number in a series of numbers in an array.
  * `x-or-fun.swift` -- an example in Swift on how xor operation can be used to solve a problem related array.
* `gates-in-c` -- demonstrates how to implement gates programmatically, related to Exercise 3.
* `bit-settings` -- an example of *binary* AND and OR operations and how to use them in bit manipulation. The example manages eight on/off settings with one byte. More information in the code comments.


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

