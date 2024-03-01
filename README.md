
1. feladat
Matematikai értelemben egy számsorozat a pozitív egész számok halmazán értelmezett valós értékű
függvény. Máshogy fogalmazva egy adott sorszámhoz egyértelmű módon hozzárendelünk egy valós
számot. A sorszám jelöli, hogy hányadik helyen áll az adott érték a számok sorozatában. (A sorszámozás
1-gyel kezdődik.)
A következő feladatok számsorozatokkal kapcsolatosak. A kérdésekre adott válaszoknak megfelelő
számokat kell eredményül beküldeni.

a) Képezzük a következő számsorozatot:
A sorozat 1. eleme az 1. Minden további elemét a sorozatnak úgy kapjuk, hogy az előző elem
számjegyeit szorozzuk 2-vel és az eredményeket rendre egymás után írjuk.
Pl.: A sorozat néhány eleme: 1 2 4 8 16 212 424 848 16816 ...
Mi lesz ennek a sorozatnak a 21. eleme? Beküldendő egy szám (a válasz a kérdésre).
(3 pont)

b) Melyik az a legkisebb kétjegyű természetes szám, amelyet az a) feladat algoritmusához
kezdőértékként (1. elem) használva a sorozatban lesz olyan szám (legfeljebb 30 lépésen/sorozatelemen
belül), amelynek az utolsó 27 számjegye a 216816212162121681684816816? Beküldendő egy szám (a
válasz a kérdésre). (4 pont)

c) Képezzük a következő számsorozatot:
A sorozat első eleme a 11. Minden további elemet úgy kapunk, hogy az előző elem számjegyeinek
összegét az előző elem végére írjuk.
Pl.: 11 112 1124 11248 1124816 112481623 ...
Mi lesz ennek a sorozatnak a 31. eleme? Beküldendő egy szám (a válasz a kérdésre).
(3 pont)

2. feladat

A sakkjátékot két játékos játssza egymás ellen a
négyzet alakú, nyolc sorra és nyolc oszlopra felosztott
sakktáblán, 16–16, azaz összesen 32 bábuval. A két
játékos bábui eltérő színűek. A színek elnevezése
világos, illetve sötét. A játékosok felváltva lépnek,
mindig a világos kezd (övé az első lépés).
A tábla sorai 1-től 8-ig számozottak, az oszlopok pedig
a-tól h-ig az angol abc betűivel betűzöttek. Így
minden mezőnek van egy koordinátája. Például d6,
ami 5. oszlop 6. sorának mezőjét jelzi. Lásd ábra!
A játék szabályairól és az egyes bábuk lépési
lehetőségeiről lásd például:
https://hu.wikipedia.org/wiki/Sakk
A sakkjátszmák lejegyzésénél egységes jelölésrendszert használunk. A legelterjedtebb az úgynevezett
algebrai lejegyzés.
Lásd például: https://hu.wikipedia.org/wiki/A_sakkj%C3%A1tszm%C3%A1k_lejegyz%C3%A9se
A jatszmak.txt fájl néhány sakkjátszma lejegyzett lépéseit tartalmazza. A fájl minden sorában egy-egy
játszma lépései szerepelnek. A játszmák száma legfeljebb 30.
A fájl soraiban a lépéseket tabulátor választja el. Egy sorban legfeljebb 100 tabulátorral határolt lépés
szerepel.
Minden játszmát a világos kezdi és a játékosok lépései felváltva követik egymást. Az utolsó lépés után
az ellenfél veszített (vagy mattot kapott, vagy feladta a játszmát), döntetlen mérkőzést nem tartalmaz
a fájl.
A lépések értelmezése (a fájlban található jelölésrendszer):
Először a lépést megtevő bábu betűjele szerepel (mindig nagy betű), kivéve a gyalog esetén, mert ott
nem jelöljük a bábut. A bábuk betűjelei: K-király; V-vezér; B-bástya; F-futó; H-huszár.
A bábu betűjele után a lépés érkezési mezőjének koordinátái szerepelnek. (A kiindulópont koordinátái
nem!)
Pl.: Kh7 – király lép a h7-re; Bd4 – bástya lép d4-re; e4 – gyalog lép e4-re.
Ha az érkezési mezőn már állt az ellenfélnek egy bábuja, akkor a lépésnél azt a bábut leütik. Ennek
jelölése a bábu betűjele utáni x.
Pl.: Fxb1 – futó üti a b1-en álló figurát és a b1-re lép; Kxg5 – király üti a g5-ön lévő figurát és a g5-
re lép.
8
7
6
5
4
3
2
1
a b c d e f g h
d6
Ha a gyalog üt, akkor az x elé azon vonal betűjele kerül, amelyről indulva történt az ütés.
Pl.: hxe6 – gyalog üti a h vonalról indulva a e6-on álló figurát és az e6-ra lép.
A sakkban egy speciális lépés a sáncolás, amelynél egyetlen lépésben két bábu mozog (király és bástya).
Két változat lehetséges, a rövid sáncolás és a hosszú sáncolás. A lépés geometriáját az ábrák
szemléltetik.
Rövid sánc Hosszú sánc
A fájlban a rövid sáncot a O-O, míg a hosszú sáncot O-O-O kódolja. (Nagy „O” betűk.)
A jatszmak.txt fájl adatai alapján oldja meg a következő feladatokat!

a) A forrásfájlban tárolt mérkőzéseken ki nyert? Adja meg a fájlban szereplő valamennyi mérkőzés
esetén, hogy világos vagy sötét volt-e a győztes! A beküldendő egy karaktersorozat, amely a fájlban
szereplő mérkőzések sorrendjében tartalmazza a „v” illetve „s” karaktereket, attól függően, hogy
világos vagy sötét nyerte az adott mérkőzést. (2 pont)

Pl.: Ha például a fájlban 3 mérkőzés adatai szerepelnek és az eredmények rendre: 1. mérkőzés: sötét
győzött; 2. mérkőzés: világos győzött; 3. mérkőzés: világos győzött, akkor a beküldendő
karaktersorozat: „svv”. (Csupa kisbetűvel, határoló karakterek nélkül.)

b) A fájlban tárolt mérkőzéseken összesen hány mezőn haladtak keresztül a lépéseik során a huszárok
(sötét és világos) együttesen? (A huszár egy lépés során 4 mezőn halad keresztül.) Beküldendő egy szám
(a válasz a kérdésre). (2 pont)

c) A fájlban tárolt mérkőzések közül melyek voltak azok, amelyikben leütötték legalább az egyik vezért?
A mérkőzések sorszámát adja meg! A sorszámozás 1-gyel kezdődik. A sorszámokat „;”-vel válassza el!
(7 pont)

Pl.: ha a 2., 5. és 6. mérkőzésen ütöttek le vezért, akkor a válasz: 2;5;6 A mérkőzések sorszámát
növekedő sorrendben kell megadni, a beküldött karaktersorozat ne tartalmazzon szóközt!

d) A fájlban tárolt mérkőzéseken összesen hány mezőt léptek a vezérek (világos és sötét együtt)?
Beküldendő egy szám (a válasz a kérdésre). A vezér lépéslehetőségeit például a
https://hu.wikipedia.org/wiki/Sakk linken nézheti meg. (7 pont)

Pl.: Ha a vezér az a2-es mezőről az a7-es mezőre lép, akkor összesen 5 mezőt lépett. Ha a vezér az
a2-es mezőről a d2-es mezőre lép, akkor 3 mezőt lépett. Ha a vezér az a2-es mezőről a e6-os mezőre
lép, akkor 4 mezőt lépett. Tehát azt a mezőt nem kell számolni, amelyen a vezér állt.

e) Hány olyan mérkőzés van a fájlban tároltak közül, ahol a világos király végig a helyén maradt? Tehát
nem léptek vele. Beküldendő egy szám (a válasz a kérdésre). (3 pont)

f) A fájlban tárolt mérkőzések között hány olyan van, ahol a mérkőzés végén több, mint 20 bábu maradt
a táblán? Sötét és világos bábuk együttesen. Beküldendő egy szám (a válasz a kérdésre).
(3 pont)
