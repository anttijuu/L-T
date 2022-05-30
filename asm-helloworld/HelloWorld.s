//
// Assembler program to print "Heippa maailma!"
// to stdout.
//
// X0-X2 - parameters to OS function services
// X16 - OS function number
//
.global _start             // Provide program starting address to linker
.align 2

// Setup the parameters to print hello world
// and then call OS to do it.

_start: mov X0, #1         // 1 = StdOut
        adr X1, helloworld // string to print
        mov X2, #16        // length of our string
        mov X16, #4        // macOS write system call
        svc 0              // Call OS to output the string

// Setup the parameters to exit the program
// and then call OS to do it.

        mov     X0, #0      // Use 0 return code
        mov     X16, #1     // Service command code 1 terminates this program
        svc     0           // Call OS to terminate the program

helloworld:      .ascii  "Heippa maailma!\n"

