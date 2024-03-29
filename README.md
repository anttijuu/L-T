# Demot ja esimerkit

Nämä demot havainnollistavat eri asioita siitä miten tietokoneet toimivat, ohjelmoijan näkökulmasta.

Näitä käytetään peruskurssilla tietokoneista. Kurssilla **koodiesimerkkien tutkiminen lähdekoodina riittää**. Demot esitellään kurssin opetustapahtumissa. 

## Sisältö

* `asm-helloworld` -- yksinkertainen assembly -kielellä tehty hello world -sovellus macOS:lle.
* `double-rounding` -- esimerkkejä tilanteista joissa liukulukujen pyöristys tai epätarkkuus aiheuttaa ongelmia. Esimerkkikielinä C, Java ja Swift.
* `divbyzero` -- nollalla jakamisen virhe:
  * `divbyzero.c` -- esimerkki C -kielellä, joka demonstroi nollalla jakamisen. Tosin useimmilla kääntäjillä tämä ei näytä *miltään* sillä tuloksena C -kielessä nollalla jakamisesta on ns. "undefined behaviour" -- ohjelma voi tällaisessa tilanteessa tehdä *ihan mitä tahansa*.
  * `DivByZero.java`, `DivByZero.swift` -- esimerkkejä siitä, miten korkeamman tason (kuin C) ohjelmointikielet Java ja Swift ilmoittavat nollalla jakamisesta virheellä.
* `overflow` -- useita esimerkkejä siitä miten kokonaisluvun ylivuoto tapahtuu eri ohjelmintikielillä.
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
* `memory` -- muistiin liittyviä demoja.
  * `address.c` -- tulostetaan muuttujan arvo, muttujan osoite, muuttujaan osoittavan osoittimen osoite, jne.
  * `endian.cpp` -- tulostaa muistissa olevan muuttujan tavut, josta selviää onko kone little vai big endian. Mukana kaksi tulostusta macOS laitteilta sekä x86 että aarch64 prosessoriarkkitehtuureista.
  * `stackoverflow.c` -- havainnollistaa rekursion kautta tapahtuvaa pinomuistin ylivuotoa (stack overflow). Koodia muokkaamalla pinon ylivuodon saa korjattua kun käytetään muuttujaa varten kekomuistia (heap).
* `fun` -- hauskoja demoja :)
  * `Planets.swift` -- tulostaa planeettojen symbolit Unicode -merkkeinä. Pluto mukana.
  * `spooky.swift` -- esimerkki siitä miten moderneilla ohjelmointikielillä voidaan käyttää lähes mitä tahansa Unicode -symboleita muuttujien ja funktioiden nimissä ja muuttujien arvoissa -- jopa emojeita!
  * `x-or-fun.c` -- C -kielinen esimerkki siitä miten xor -operaatioita voidaan hyödyntää taulukoihin liittyvän ongelman ratkaisemiseen -- miten löydetään taulukosta puuttuva numero.
  * `x-or-fun.swift` -- sama kuin yllä, mutta Swift -ohjelmointikielellä.
* `gates-in-c` -- demonstroi porttien (gate) toteutusta ohjelmallisesti, liittyen harjoitukseen 3.
* `bit-settings` -- esimerkki *binääristen* AND ja OR -operaatioiden käytöstä bittien manipuloimisessa. Esimerkissä hoidetaan kahdeksan on/off -tyyppisen asetuksen hallinta yhdellä tavulla. Yhden bitin kääntämisellä voidaan myös muuntaa iso ASCII -kirjain pieneksi kirjaimeksi. Koodin kommenteissa lisätietoa aiheesta.
* `unicode-char` -- esimerkki siitä miten erikoismerkit kuten skandinaaviset kirjaimet, saamen kielen kirjaimet, sekä venäjän ja japaninkieliset kirjaimet eivät näy oikein ellei ohjelma käytä leveitä merkkejä (wide char) kahdeksanbittisten merkkien käsittelyyn. Vaikka leveitä merkkejä käytettäisiinkin, voi olla ettei tietokoneesi ja sen terminaaliohjelma osaa näyttää Unicode -merkkejä. Windows on tässä aika huono. Lisäksi käytetyn terminaaliohjelman pitää tukea Unicodea, ja fontti jolla kirjaimet esitetään, pitää sisältää näiden kielten merkit jotta ne voitaisiin esittää näytöllä. Tämä ohjelma vaatii kääntämiseen C++:n.

## Kääntäminen ja suorittaminen

Jos haluat itse kokeilla kääntämistä ja suorittamista, alla siihen ohjeet.

Koodiesimerkkien ja demojen suorittaminen edellyttää että koneelle on asennettu kyseisen kielen työkalut:

* C: joko GCC tai clang -kääntäjä: esim https://gcc.gnu.org
* Java: Java Development Kit (JDK): https://jdk.java.net/18/
* Swift: Swift -kääntäjä: macOS: asenna Xcode, muut: https://www.swift.org/download/

Yleensä eri ohjelmistokehitystyökalujen asentaminen joko asentaa kääntäjän tai tarjoaa helpon tavan asentaa kääntäjiä eri kielille. Kysy lisää opettajilta jos tarpeen.

### C -kielisen ohjelman kääntäminen komentoriviltä:

Windowsissa ohjelmatiedostojen nimi on tyypillisesti esim. `ohjelma.exe`, joten muuta ao komentoa jos käytät Windowsia.

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

