# ND1-3
namų darbas 1-3
## versijos

v0.1  https://github.com/justinasvalaika/ND1-3/tree/v0.1
Veikimas:
  Suvedamas vardas; pavardė.
  Klausiama ar norima generuoti pažymius atsitiktinai. T, t paspaudus generuos atsitiktinai, prieš tai paklaus kelis pažymius generuoti, paspaudus ką nors kitką reikės vesti ranka. Ranka pažymiai vedami iki tol kol parašomas  nulis (0).
  Klausiama ar bus kitas studentas (įrašas). T/t bus, N/n, nebus.
  Pabaigus įvedimą klausiama vidurkį ar medianą išvesti. V/v vidurkis; M/m mediana.
  Sugeneruojama lentelė.

v0.2 https://github.com/justinasvalaika/ND1-3/tree/v0.2
Itrauktas automatinis lentelės nuskaitymas klasiokai.txt
Rezultatų išvedimas rūšiuojant-pagal pavardes.

v0.3 https://github.com/justinasvalaika/ND1-3/tree/v0.3
Perkelta viskaas į headerius

v0.4 https://github.com/justinasvalaika/ND1-3/tree/v0.4
Papildyta automatiniu failu sarasu generavimu, nuskaitymu, isrusiavimu ir israsymo i skirtingus failus Grauzikai.txt ir Tinginiai.txt;
Paleidus programa klausia ar rasysim ranka ar generuosim automatiskai, pasirenkama g-automatiniam failų generavimui.
Generuojami failai desimt.txt, simtas.txt, stuka.txt, 10k.txt, 100k.txt su atitinkamais kiekiais  irasu. Vardai ir pavardes generuojami sabloniski. Pries kiekviena varda yra skaicius, reiskiantis is kurio failo is situ 5 yra.
Tada visi 5 failai vienas po kito nuskaitomi, sugeneruojamas is pazymiu ir egzamino vidurkis, irasomi i vektoriu.
Vektoriuje failai surusiuojami nuo maziausio iki didziausio galutinio pazymio.
Duomenys isvedami i du skirtingus failus:
Tinginiai.txt kai galutiis <5
Grauzikai.txt kai galutinis >5
Greičio duomenys: (faile: Laikai su debugu.png):
failų generavimas su atsitiktiniu irasu kiekiu:
kiekis, vnt       laikas, ms
10-                1,554
100-              2,063
1000-              10,324
10000-             79,823
100000-            769,665
Failu nuskaitymas (visu 5) ir surasymas duomenu i vektoriu: 554,897 ms;
Vektoriaus isvedimas i du skirtingus failus: 1230,51 ms;
![rezultatai](https://imgur.com/SNUss8m.png)


