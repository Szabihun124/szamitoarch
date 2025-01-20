#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/////////
#define versenySzam 5
#define maxNevHossz 50

struct Futamido
{
    int *ora;
    int *perc;
    int *masodperc;
};
//////
void tombKiir(char tomb[][maxNevHossz], struct Futamido ido, int hossz);
int idoMasodpercben(struct Futamido ido, int sorszam);
////////
int main()
{
    char versenyzokNeve[versenySzam][maxNevHossz] = {"Hamilton", "Verstappen", "Vettel", "Leclerc", "Raikkonen"};
    struct Futamido ido;
    ido.ora = (int *)malloc(versenySzam * sizeof(int));
    ido.perc = (int *)malloc(versenySzam * sizeof(int));
    ido.masodperc = (int *)malloc(versenySzam * sizeof(int));

    int oraInit[versenySzam] = {1, 1, 1, 1, 1};
    int percInit[versenySzam] = {36, 36, 40, 42, 44};
    int mpInit[versenySzam] = {12, 20, 23, 45, 25};
    for (int i = 0; i < versenySzam; i++)
    {
        ido.ora[i] = oraInit[i];
        ido.perc[i] = percInit[i];
        ido.masodperc[i] = mpInit[i];
    }
    //////

    tombKiir(versenyzokNeve, ido, versenySzam);
    /////
    int sorszam;
    while (1)
    {
        printf("\n Adja meg egy versenyző sorszámáz (1-%d)", versenySzam);
        if (scanf("%d", &sorszam) == 1 && sorszam >= 1 && sorszam <= versenySzam)
        {
            break; // Érvényes bemenet
        }
        else
        {
            printf("Érvénytelen sorszám, próbálja meg újra!\n");
            while (getchar() != '\n')
            {
            };
        }
    }

    int masodpercekben = idoMasodpercben(ido, sorszam - 1);
    printf("\n%d. versenyző futamideje másodpercben: %d\n ", sorszam, masodpercekben);

    /////////
    int versenyzokIdejeMp[versenySzam];
    // printf("\nVersenyzőSorszáma,Versenyzőneve,VersenyzőIdejeMpBen");
    FILE *file = fopen("versenyzok.txt", "w");
    if (file == NULL)
    {
        printf("HIBA: Nem sikerült megnyitni a fájlt!\n");
        return 1;
    }
    for (int i = 0; i < versenySzam; i++)
    {
        versenyzokIdejeMp[i] = idoMasodpercben(ido, i);
        printf("\n%d. %s, : %d", i + 1, versenyzokNeve[i], versenyzokIdejeMp[i]);
        fprintf(file, "\n%d. %s, : %d", i + 1, versenyzokNeve[i], versenyzokIdejeMp[i]);
    }
    //////    
    fclose(file);
    printf("\nVersenyzők adatai sikeresen fájlba írva!\n");

    int alsohatar, felsohatar;
    srand(time(0));
    alsohatar = rand() % 3201 + 3600;
    do
    {
        printf("Az alsó határ: %d\n", alsohatar);
        printf("Adja meg a felső határt (nagyobb mint %d): ",alsohatar);
        scanf("%d", &felsohatar);
        if (felsohatar <=alsohatar)
        {
            printf("HIBA: A felső határnak nagyobbnak kell lennie az alsó határnál\n");
        }
        
    } while (felsohatar <=alsohatar);
    printf("Az intervallum [%d, %d]lett\n", alsohatar, felsohatar);
    //////
    int indexek[versenySzam];
    


    //////
    free(ido.ora);
    free(ido.masodperc);
    free(ido.perc);
    return 0;
}
/////
void tombKiir(char tomb[][maxNevHossz], struct Futamido ido, int hossz)
{
    for (int i = 0; i < hossz; i++)
    {
        printf("%d.Számú versenyző neve: %s || futam ideje:   %d:%d:%d\n", i + 1, tomb[i], ido.ora[i], ido.perc[i], ido.masodperc[i]);
    }
}
int idoMasodpercben(struct Futamido ido, int sorszam)
{
    return ido.ora[sorszam] * 3600 + ido.perc[sorszam] * 60 + ido.masodperc[sorszam];
}
////////////
