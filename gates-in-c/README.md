# Gates in C

## Suomeksi

Tämä tiedosto toteuttaa Laitteet ja tietoverkot -kurssin Harjoituksen 3 portit C -kielellä. Toteutus noudattaa malliratkaisua josta löytyy demovideo Moodlessa.

Harjoituksessa on tavoitteena toteuttaa loogisia portteja (gate) lähtökohtana AND ja NOT -portit. Koodi ei siis käytä C-kielen loogisista operaattoreista muita kuin `&&` ja `!`, vaan rakentaa muut operaattorit näistä.

## English

This file implements the Devices and data networks course Exercise 3 gates in C language. The implementation follows the sample solution video demonstration in Moodle. The goal of the exercise is to implement various ports starting from AND and NOT gates. Therefore, the code uses only the C language logical operators `&&` and `!`, and uses these to build the rest of the logical operators.

## Kääntäminen / Building 

Compile on *nix machines:

```console
> gcc *.c -o gates
```

Compile on Windows:

```console
> gcc *.c -o gates.exe
```

Or use clang instead of gcc if you prefer.

Then execute the binary to see the results. 

A sample output is included in `gates-output.txt`.

(c) Antti Juustila, 2022.
