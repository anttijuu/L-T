# Demos and samples

The demonstrations illustrate certain aspects of how computers work, from the programmer's viewpoint.

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
  * `x-or-fun.c` -- an example in C on how xor operation can be used to solve a problem related array; how to find a missing number in a series of numbers.
  * `x-or-fun.swift` -- an example in Swift on how xor operation can be used to solve a problem related array.

## Compiling and executing

In this course **it is enought to study the source code**. Demos will be presented in the course teaching events. 

If you wish to try out compiling and executing the demos yourself, instructions can be found below.

Compiling and running the demos require that you install the necessary compilers etc. for the languages:

* C: either GCC or clang compiler: esim https://gcc.gnu.org
* Java: Java Development Kit (JDK): https://jdk.java.net/18/
* Swift: Swift tools: macOS: install Xcode, others: https://www.swift.org/download/

Usually installing any software development kit installs or provides easy ways to install compilers. Ask more from teachers if needed.

### Compiling a C program from the terminal:

```console
gcc file.c -o app
```

After which, execute the "app" file from the terminal.

### Compiling a Java program from the terminal:

```console
javac File.java
```
And execute it:

```console
Java File
```

### Compiling a Swift program from the terminal:

```console
swiftc file.swift -o app
```

After which, execute the "app" file from the terminal.

