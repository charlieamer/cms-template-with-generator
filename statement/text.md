# Zlatni omjer
Dat vam je niz dimenzija prozora. Potrebno je da nađete koji prozor je najbliži *zlatnom omjeru*. Zlatni omjer dva broja se desi kada je jedan broj **φ** puta veći od drugog.

Broj **φ** je konstanta i računa se na sljedeći način:
```
φ = (1 + sqrt(5)) / 2 ≈ 1.61803398875
```
Gdje `sqrt` znači "korijen".

Na primjer, prozor dimenzija `50.0` i `30.9` je bliži *zlatnom omjeru* (sa omjerom `~1.62`) nego prozor dimenzija `50.0` i `100.0` (sa omjerom `2.0`).

*Za računanje omjera nije bitno da li se gleda `širina / visina` ili `visina / širina`. Koji god od ova dva broja su bliži zlatnom omjeru, taj omjer se uzima.*

## Ulaz
Na ulazu se u prvoj liniji nalazi broj `N`. To predstavlja broj prozora koje treba provjeriti.
U narednih `N` redova se nalaze po dva **decimalna** broja u jednom redu, razdvojeni razmakom. Ta dva broja predstavljaju širinu a zatim visinu prozora.

## Izlaz
Na izlazu u jednoj liniji treba ispisati indeks prozora čiji je omjer dimenzija najbliži *zlatnom omjeru*. Indeksi počinju od broja 0. Na primjer ako je rezultat "drugi prozor", na izlaz treba ispisati `1`.

## Ograničenja
```
0 < Širina, Visina <= 100000.0
1 <= N <= 100000
```
### Podzadaci
- 25% bodova
```
1 <= N <= 500
```

- 75% bodova - ograničenja iz sekcije **ograničenja**

## Primjeri
### Ulaz
```
5
1 2
5 6
4 3
8 7
9 10
```
### Izlaz
```
2
```
### Objašnjenje
Ovo su omjeri svih unosa:
- 1 2 - 2/1 = 2
- 5 6 - 5/6 = 1.2
- 4 3 - 4/3 = 1.33333
- 8 7 - 7/8 = 1.14286
- 9 10- 9/10= 1.11111

Najbliži unos je treći (index `2`), sa omjerom 1.33333.

## Zanimljivost *(neobavezno za čitati)*
*Zlatni omjer* je jedna zanimljiva matematicka konstanta, koja se nerijetko pojavljuje u prirodi (na primjer, razni omjeri na ljudskom licu).

Također, ukoliko su dvije dimenzije u *zlatnom omjeru* ljudski um često percipira takvu stvar "lijepom". Mnoge moderne firme uključuju zlatni omjer u svojim dizajnovima. Tako da zlatni omjer možemo naći na logotipu Apple-a, Google-a, Pepsi-a, kao i na starom web dizajnu Twittera.
