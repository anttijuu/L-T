# Rounding of doubles

Here you can find different source code examples here show how double data type may lead to issues when used in calculations.


## Rounding errors in Java and C

This example shows how rounding errors with Java double data type may occur.

Code from `Rounding.java` is below:

```Java
public class Rounding {
    public static void main(String [] args) {
        double number1 = 0.3137;
        double number2 = 0.2124;
        double result = number1 - number2;
        System.out.format("%.20f - %.20f = %.20f%n", number1, number2, result);
    }
}
```
And what is the result is when compiling and running the code:

```console
0,31370000000000000000 - 0,21240000000000000000 = 0,10129999999999997000
```
When you use a calculator or calculate this with pencil, you get 0.1013. The value is close but not exact. 

The same implemented using C from `double-rounding.c` file:

```C
int main() {
   double number1 = 0.3137;
   double number2 = 0.2124;
   double result = number1 - number2;
   printf("%.20f - %.20f = %.20f\n", number1, number2, result);
   return 0;
}
```

This prints out:

```console
0.31369999999999997886 - 0.21240000000000000546 = 0.10129999999999997340
```

Similarily to Java, double numbers are not exact, and then result into rounding errors when used in calculations, depending on the values used.

Similar example with Swift language. Code is from `double-rounding.swift`:

```Swift
let number1 = 0.3
let number2 = 0.2

let result = number1 - number2
print("\(result)")
```

One would expect the difference to be 0.1, but instead, the app output is:

```console
0.09999999999999998
```

Again close but not exact. That is why you should not compare double values using equals operator, as we see from additional examples below.

## d-round.c

The code here tries to adjust a compass direction of a boat to the desired direction, little by little.

Because rounding errors happen, and code tries to hit the exact target compass direction (`current != target`), it will never get there due to rounding errors and the compared values never being the absolutely exactly same values:

```C
double adjustHeading(double target, double current) {
   while (current != target) {
      if (current < target) {
         current += nudgeClockwise;
      } else {
         current += nudgeAntiClockwise;
      }
```

Output is then:

```console
...
...current 275.1999999908 target 275.2100000000
...current 275.2099999908 target 275.2100000000
...current 275.2199999908 target 275.2100000000
...current 275.1699999908 target 275.2100000000
...current 275.1799999908 target 275.2100000000
...current 275.1899999908 target 275.2100000000
...current 275.1999999908 target 275.2100000000
...current 275.2099999908 target 275.2100000000
...
```
And the code never hits the exactly the correct direction 275.21 and keeps adjusting...

So when comparing, there should be some tolerance in comparing values:

```C
const double TOLERANCE = 0.1; // .1 degree tolerance is ok, could be larger.

double adjustHeading(double target, double current) {
   while (fabs(current - target) > TOLERANCE) {
      if (current < target) {
         current += nudgeClockwise;
      } else {
         current += nudgeAntiClockwise;
      }
...
```
And now the adjusting stops when close enough to the intended compass direction:

```console
...current 275.0899999999 target 275.2100000000
...current 275.0999999999 target 275.2100000000
...current 275.1099999999 target 275.2100000000
...current 275.1199999999 target 275.2100000000
Current heading is 275.1199999999 towards target 275.2100000000
```

## discount.c

Here code tries to check if customer is entitle to a discount if order value is at the discount limit or over:

```C
   if (fullPrice > discountLimit) {
      printf("Entitled for discount\n");
   } else {
      printf("Not entitled for discount\n");
   }
```
But the progammer didn't remember that numbers, when money, are rounded with specific rules:

```console
full price is: 1499.999760
discountLimit is: 1500.000000
Not entitled for discount
```

Here the sum should be rounded upwards to 1500.00 according to the rounding rules of money. Customer should be entitled to the discount:

```C
const double TOLERANCE = 0.01;

   if (fullPrice > discountLimit || fabs(fullPrice - discountLimit) <= TOLERANCE) {
      printf("Entitled for discount\n");
   } else {
      printf("Not entitled for discount\n");
   }
```
So, if the sum is near enough (even though smaller) than the discount limit, customer is entitled to a discount.
