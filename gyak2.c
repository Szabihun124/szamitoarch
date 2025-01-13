#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
////
#define SIZE 10
#define MAXSTRING 20

typedef struct
{
    int *tomb;
    int meret;

} Kivalogatas;

typedef struct
{
    int *alacsony;
    int *magas;
    int meret;
} Szetvalogatas;

void tombFeltolt(int testMagassag[], int meret, int also, int felso);
void tombKiir(int tomb[], int meret, const char *uzenet);
void tombRendez(int tomb[], int meret);
Kivalogatas kivalogat(int tomb[], int meret, const char *tipus);
int tombSzetvalogat(int tomb[], int meret);

/////
int main()
{
    int testMagassag[SIZE];
    srand((unsigned int)time(NULL));
    tombFeltolt(testMagassag, SIZE, 160, 190);
    char tipus[MAXSTRING];
    ///
    tombRendez(testMagassag, SIZE);
    tombKiir(testMagassag, SIZE, "A tomb elemei: ");

    /////
    do
    {
        printf("Adjon meg egy típust ( alacsony, magas):\n");
        scanf("%s", tipus);
    } while (strcmp(tipus, "alacsony") != 0 && strcmp(tipus, "magas") != 0);

    Kivalogatas kivalasztott = kivalogat(testMagassag, SIZE, tipus);
    tombKiir(kivalasztott.tomb, kivalasztott.meret, "Kivalogatott elemek:");
    ///
    
    return 0;
}
void tombFeltolt(int testMagassag[], int meret, int also, int felso)
{
    for (int i = 0; i < meret; i++)
    {
        testMagassag[i] = also + rand() % (also - felso + 1);
    }
}
void tombKiir(int tomb[], int meret, const char *uzenet)
{
    printf("%s\n", uzenet);
    for (int i = 0; i < meret; i++)
    {
        printf("%d\n", tomb[i]);
    }
}
void tombRendez(int tomb[], int meret)
{
    for (int i = 0; i < meret - 1; i++)
    {
        int max_idx = i;
        for (int j = i + 1; j < meret; j++)
        {
            if (tomb[j] > tomb[max_idx])
            {
                max_idx = j;
            }
        }
        if (max_idx != i)
        {
            double temp = tomb[i];
            tomb[i] = tomb[max_idx];
            tomb[max_idx] = temp;
        }
    }
}
//
Kivalogatas kivalogat(int tomb[], int meret, const char *tipus)
{
    Kivalogatas eredmeny;
    eredmeny.tomb = (int *)malloc(meret * sizeof(int));
    eredmeny.meret = 0;

    for (int i = 0; i < meret; i++)
    {
        if (
            (strcmp(tipus, "alacsony") == 0 && tomb[i] < 170) || strcmp(tipus, "magas") == 0 && tomb[i] > 170)
        {
            eredmeny.tomb[eredmeny.meret++] = tomb[i];
        }
    }

    return eredmeny;
}
int tombSzetvalogat(int tomb[], int meret)
{
    for (int i = 0; i < meret; i++)
    {
        Szetvalogatas eredmeny;
        if (tomb[i] > 170)
        {
            eredmeny.magas[eredmeny.meret++] = tomb[i];
        }else{
            eredmeny.alacsony[eredmeny.meret] = tomb[i];
        }
        
    }
    


}
