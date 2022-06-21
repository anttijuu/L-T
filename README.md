# Demot ja esimerkit

Nämä demot havainnollistavat eri asioita siitä miten tietokoneet toimivat, ohjelmoijan näkökulmasta.

Näitä käytetään peruskurssilla tietokoneista. Kurssilla **koodiesimerkkien tutkiminen lähdekoodina riittää**. Demot esitellään kurssin opetustapahtumissa. 

## Sisältö

* `asm-helloworld` -- yksinkertainen assembly -kielellä tehty hello world -sovellus macOS:lle.
* `double-rounding` -- esimerkkejä tilanteista joissa liukulukujen pyöristys tai epätarkkuus aiheuttaa ongelmia. Esimerkkikielinä C, Java ja Swift.
* `divbyzero` -- nollalla jakamisen virhe:
  * `divbyzero.c` -- esimerkki C -kielellä, joka näyttää miten ohjelma kaatuu kun luku jaetaan nollalla.
* `overflow` -- useita esimerkkejä siitä miten kokonaisluvun ylivuioto tapahtuu eri ohjelmintikielillä.
  * `main.c` -- kokonaisluvun ylivuotoesimerkki C -kielellä.
  * `main.swift` -- kuten yllä, mutta ohjelmointikielenä Swift. 
  * `overflow.c` -- kahdeksanbittisten kokonaislukujen ylivuotoesimerkki C -kielellä.
  * `overflow.swift` -- kahdeksanbittisten kokonaislukujen ylivuotoesimerkki Swift -kielellä.
* `printformat` -- numeroarvon tulostaminen eri lukujärjestelmillä.
  * `numbinary.c` -- pitkän kokonaisluvun tulostaminen bitteinä.
  * `printformat.c` -- kokonaisluvun arvon tulostaminen eri lukujärjestelmän arvoina; merkki (char), etumerkitön kokonaisluku (unsigned), heksadesimaaliluku,...
* `shifting` -- esimerkkejä kokonaislukujen bittien liikuttelusta (bit shifting).
  * `shifting.c` -- yksinkertainen esimerkki bit shiftingistä.
  * `even-shift.c` -- esimerkki näyttää miten jakolaskuja ja kertolaskuja parillisilla numeroilla voidaan toteuttaa bittien liikuttelulla.
* `fun` -- hauskoja demoja :)
  * `spooky.swift` -- esimerkki siitä miten moderneilla ohjelmointikielillä voidaan käyttää lähes mitä tahansa Unicode -symboleita muuttujien ja funktioiden nimissä ja muuttujien arvoissa -- jopa emojeita!
  * `x-or-fun.c` -- C -kielinen esimerkki siitä miten xor -operaatioita voidaan hyödyntää taulukoihin liittyvän ongelman ratkaisemiseen -- miten löydetään taulukosta puuttuva numero.
  * `x-or-fun.swift` -- sama kuin yllä, mutta Swift -ohjelmointikielellä.

## Kääntäminen ja suorittaminen

Jos haluat itse kokeilla kääntämistä ja suorittamista, alla siihen ohjeet.

Koodiesimerkkien ja demojen suorittaminen edellyttää että koneelle on asennettu kyseisen kielen työkalut:

* C: joko GCC tai clang -kääntäjä: esim https://gcc.gnu.org
* Java: Java Development Kit (JDK): https://jdk.java.net/18/
* Swift: Swift -kääntäjä: macOS: asenna Xcode, muut: https://www.swift.org/download/

Yleensä eri ohjelmistokehitystyökalujen asentaminen joko asentaa kääntäjän tai tarjoaa helpon tavan asentaa kääntäjiä eri kielille. Kysy lisää opettajilta jos tarpeen.

### C -kielisen ohjelman kääntäminen komentoriviltä:

```console
gcc tiedosto.c -o ohjelma
```

Sen jälkeen suorita "ohjelma" -niminen tiedosto koneellasi.

Valinnaisesti käytä clang -kääntäjää, korvaa tälloin komento `gcc` komennolla `clang`.

### Java -kielisen ohjelman kääntäminen komentoriviltä:

```console
javac Tiedosto.java
```
Ja suorita ohjelma:

```console
java Tiedosto
```

### Swift -kielisen ohjelman kääntäminen komentoriviltä:

```console
swiftc tiedosto.swift -o ohjelma
```

Sen jälkeen suorita "ohjelma" -niminen tiedosto koneellasi.

