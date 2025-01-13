//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//
#define NUM_GYEREKEK 5
#define MAX_STR 20

// KivalogatasStruktura
typedef struct
{
    double *tti_tomb;
    int meret;
} Kivalogatas;
// Fügvény Dekla
void feltoltTesttomeg(int testomeg[], int meret, int also, int felso);
double szamolTTI(double testmagassag, int testtomeg);
void rendezesTTI(double tti[], int meret);
void kiirTomb(double tomb[], int meret, const char *uzenet);
Kivalogatas kivalogatTTI(double tti[], int meret, const char *tipus);
void kiirFajlba(double tomb[], int meret, const char *fajlnev);
//
int main()
{
    double testMagassag[NUM_GYEREKEK] = {1.20, 1.16, 1.52, 1.18, 1.34};
    int testtomeg[NUM_GYEREKEK];
    double tti[NUM_GYEREKEK];
    char tipus[MAX_STR];
    //
    srand((unsigned int)time(NULL));
    // Testomeg feltöltése
    feltoltTesttomeg(testtomeg, NUM_GYEREKEK, 35, 50);
    // TTI számítása
    for (int i = 0; i < NUM_GYEREKEK; i++)
    {
        tti[i] = szamolTTI(testMagassag[i], testtomeg[i]);
    }
    // TTI rendezes
    rendezesTTI(tti, NUM_GYEREKEK);
    // TTI kiírása
    kiirTomb(tti, NUM_GYEREKEK, "Rendezett TTI tömb: ");
    // Beolvasas
    do
    {
        printf("Adjon meg egy típust (sovany, normalis, elhizott): ");
        scanf("%s", tipus);
    } while (strcmp(tipus, "sovany") != 0 && strcmp(tipus, "normalis") != 0 && strcmp(tipus, "elhizott") != 0);
    // Kivalogatas
    Kivalogatas kivalasztott = kivalogatTTI(tti, NUM_GYEREKEK, tipus);
    // Kivalogatott tomb kiíratasa
    kiirTomb(kivalasztott.tti_tomb, kivalasztott.meret, "Kivalogatott TTI elemek:");
    //Fajlbaír
    kiirFajlba(kivalasztott.tti_tomb, kivalasztott.meret, "kivalasztott_tti.txt");


    // Memoria felszabadítas
    free(kivalasztott.tti_tomb);

    return 0;
}

// Testömeg
void feltoltTesttomeg(int testomeg[], int meret, int also, int felso)
{
    for (int i = 0; i < meret; i++)
    {
        testomeg[i] = also + rand() % (felso - also + 1);
    }
}
// TTI
double szamolTTI(double testmagassag, int testtomeg)
{
    return testtomeg / (testmagassag * testmagassag);
}

// TTI Rendezes
void rendezesTTI(double tti[], int meret)
{
    for (int i = 0; i < meret - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < meret; j++)
        {
            if (tti[j] > tti[max_idx])
            {
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            double temp = tti[i];
            tti[i] = tti[max_idx];
            tti[max_idx] = temp;
        }
    }
}
// Tömb kiírása
void kiirTomb(double tomb[], int meret, const char *uzenet)
{
    printf("%s\n", uzenet);
    for (int i = 0; i < meret; i++)
    {
        printf("%.2f\n", tomb[i]);
    }
}
// Kivalogat tipus
Kivalogatas kivalogatTTI(double tti[], int meret, const char *tipus)
{
    Kivalogatas eredmeny;
    eredmeny.tti_tomb = (double *)malloc(meret * sizeof(double));
    eredmeny.meret = 0;

    for (int i = 0; i < meret; i++)
    {
        if ((strcmp(tipus, "sovany") == 0 && tti[i] < 18.5) ||
            (strcmp(tipus, "normalis") == 0 && tti[i] >= 18.5 && tti[i] <= 25) ||
            (strcmp(tipus, "elhizott") == 0 && tti[i] > 25))
        {
            eredmeny.tti_tomb[eredmeny.meret++] = tti[i];
        }
    }

    return eredmeny;
}

void kiirFajlba(double tomb[], int meret, const char* fajlnev) {
    FILE* fajl = fopen(fajlnev, "w");
    if (fajl == NULL) {
        perror("Fájl megnyitása sikertelen");
        return;
    }

    for (int i = 0; i < meret; i++) {
        fprintf(fajl, "%.2f\n", tomb[i]);
    }

    fclose(fajl);
}
