# Generator za test case-ove

Ovo je template za generisanje zadatka za CMS Judge. Zadatak koji je zadan je
jednostavno sabiranje dva broja. Sadrzi i program koji sam poziva vas program
i zapisuje rjesenje u fajlove.

## TEKST ZADATKA
Tekst zadatka se nalazi u "statement/zbir.md"
(ime se moze mijenjati po potrebi). Ono sto CMS ce da gleda jeste fajl
"statement/statement.pdf", i to je fajl koji ce se vidjeti na judge. Znaci da
ce se trebati pretvoriti .md fajl u .pdf fajl (ili na bilo koji drugi nacin po
vasoj zelji napraviti fajl statement/statement.pdf, npr iz Worda).

## GENERATOR RJESENJA
Koristi CMake sistem, tako da se upoznajte s tim prvo. Moj savjet je koristiti
visual studio code + ekstenziju C/C++ Extension Pack (link je ispod).
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack

Sljedece korake trebate poduzeti za vase zadatke (redosljed nije bitan):
- Promijeniti ime projekta za CMake (opcionalno, ali preporucivo)
  - U fajlu CMakeLists.txt promijeniti liniju project(zbir) u
    project(IME_ZADATKA)
- Napisati rjesenje vaseg zadatka u "sol/main.cpp"
- Konfigurisati generator - fajl "sol/config.txt"
  - Sintaksa za ovaj fajl je sljedeca:
  - VRSTA_SUBTASKOVA BROJ_SUBTASKOVA BROJ_TESTOVA_U_SUBTASK_1 BROJ_TESTOVA_U_SUBTASK_2 ...
    - VRSTA_SUBTASKOVA moze biti global_count ili subtask_count
      - global_count znaci da na judge necete imati subtaskova, vec ce ucenik
        biti bodovan na osnovu toga koliko ima ukupno tacnih testnih primjera,
        a "subtaskovi" koje cete u generatoru dobiti su zapravo "grupe"
        taskova.
      - subtask_count znaci standardni nacin za subtaskove. Ucenik mora 100%
        primjera u jednom subtasku uraditi da bi dobio bodove za taj subtask.
- Napisati generator za vas zadatak u "sol/generator_specific.cpp"
  - U ovom template je dosao i generator za pravljenje testova za "saberi dva
    broja".
  - Od parametara imate
    - inputFile - to ce biti ulazni fajl za testni primjer.
    - subtask - koji je subtask u pitanju. Broj krece od 0
    - testcase - koji je ovo test u subtasku. Broj krece od 0
    - testPercent - koji je ovo test u subtasku izrazen u procentima. Na
                    primjer, ako imate 4 taska u subtasku, na prvom testu ovaj
                    broj je 0.0, drugom 0.33, trecem 0.66 i cetvrtom 1.0.
                    Korisno ukoliko zelite da imate inkrementalno teze testove.

## POKRETANJE
Na kraju svega treba pokrenuti generator.exe, i moraju u istom folderu biti
"main.exe" (ili main na linuxu) i config.txt se trazi u folderu
"../sol/config.txt".
