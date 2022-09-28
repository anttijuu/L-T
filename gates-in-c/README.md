# Gates in C

## Suomeksi

Tämän hakemiston lähdekooditiedostot toteuttavat Laitteet ja tietoverkot -kurssin Harjoituksen 3 portit C -kielellä. Toteutus noudattaa malliratkaisua josta löytyy demovideo Moodlessa.

Harjoituksessa on tavoitteena toteuttaa loogisia portteja (gate) lähtökohtana AND ja NOT -portit. Koodi ei siis käytä C-kielen loogisista operaattoreista muita kuin `&&` ja `!`, vaan rakentaa muut operaattorit eli portit (NAND, OR, NOR, XOR) näistä, ja vielä monimutkaisempiakin "piirejä".

## English

The source code files here implement the Devices and data networks course Exercise 3 gates in C language. The implementation follows the sample solution video demonstration in Moodle. The goal of the exercise is to implement various gates starting from AND and NOT gates. Therefore, the code uses only the C language logical operators `&&` and `!`, and uses these to build the rest of the logical operators or gates (NAND, OR, NOR, XOR) as well as more compicated "chips".

## Kääntäminen / Building 

Compile on *nix machines:

```console
> gcc -o gates *.c
```

Compile on Windows:

```console
> gcc -o gates.exe *.c
```

Or use clang instead of gcc if you prefer.

Then execute the binary to see the results. 

A sample output is included in `gates-output.txt`.

(c) Antti Juustila, 2022.
