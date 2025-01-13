#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define HETEK 13

// a) Inicializációs lista alapján hányszor volt 300 Ft alatt az árfolyam?
int hanyszorAlatt300(const double arfolyam[], int meret) {
    int szamlalo = 0;
    for (int i = 0; i < meret; i++) {
        if (arfolyam[i] < 300.0) {
            szamlalo++;
        }
    }
    return szamlalo;
}

// b) Monoton növekedés ellenőrzése
bool monotonNottE(const double arfolyam[], int meret) {
    for (int i = 1; i < meret; i++) {
        if (arfolyam[i] < arfolyam[i - 1]) {
            return false;
        }
    }
    return true;
}

// c) Véletlenszerű feltöltés, legnagyobb és legkisebb érték keresése
void feltoltVeletlen(double arfolyam[], int meret, double min, double max) {
    for (int i = 0; i < meret; i++) {
        arfolyam[i] = min + (rand() / (double)RAND_MAX) * (max - min);
    }
}

void szelsoertekek(const double arfolyam[], int meret, int* legkisebbIndex, int* legnagyobbIndex) {
    *legkisebbIndex = 0;
    *legnagyobbIndex = 0;
    for (int i = 1; i < meret; i++) {
        if (arfolyam[i] < arfolyam[*legkisebbIndex]) {
            *legkisebbIndex = i;
        }
        if (arfolyam[i] > arfolyam[*legnagyobbIndex]) {
            *legnagyobbIndex = i;
        }
    }
}

// d) Átlag számítása és eltérések kiírása
double atlagArfolyam(const double arfolyam[], int meret) {
    double osszeg = 0.0;
    for (int i = 0; i < meret; i++) {
        osszeg += arfolyam[i];
    }
    return osszeg / meret;
}

void kiirEltérés(const double arfolyam[], int meret, double atlag) {
    for (int i = 0; i < meret; i++) {
        printf("%d. hét: Árfolyam = %.2f, Eltérés = %+0.2f\n", i + 1, arfolyam[i], arfolyam[i] - atlag);
    }
}

int main() {
    double arfolyam[HETEK] = {302.5, 298.4, 305.2, 299.8, 301.0, 303.3, 307.1, 300.5, 299.0, 295.2, 298.8, 303.7, 306.0};

    // a) Hányszor volt 300 Ft alatt az árfolyam?
    printf("a) 300 Ft alatt %d alkalommal volt az árfolyam.\n", hanyszorAlatt300(arfolyam, HETEK));

    // b) Monoton növekedés ellenőrzése
    printf("b) Az árfolyam %s.\n", monotonNottE(arfolyam, HETEK) ? "monoton nőtt" : "nem nőtt monoton");

    // c) Véletlenszerű feltöltés, szélsőértékek keresése
    srand((unsigned int)time(NULL));
    double randomArfolyam[HETEK];
    feltoltVeletlen(randomArfolyam, HETEK, 290.0, 310.0);

    int legkisebbIndex, legnagyobbIndex;
    szelsoertekek(randomArfolyam, HETEK, &legkisebbIndex, &legnagyobbIndex);

    printf("c) Véletlenszerű árfolyam tömb:\n");
    for (int i = 0; i < HETEK; i++) {
        printf("%d. hét: %.2f\n", i + 1, randomArfolyam[i]);
    }

    printf("\nA legkisebb árfolyam a %d. héten: %.2f\n", legkisebbIndex + 1, randomArfolyam[legkisebbIndex]);
    printf("A legnagyobb árfolyam a %d. héten: %.2f\n", legnagyobbIndex + 1, randomArfolyam[legnagyobbIndex]);

    // d) Átlag és eltérések kiírása
    double atlag = atlagArfolyam(randomArfolyam, HETEK);
    printf("\nd) Átlagos árfolyam: %.2f\n", atlag);
    kiirEltérés(randomArfolyam, HETEK, atlag);

    return 0;
}
