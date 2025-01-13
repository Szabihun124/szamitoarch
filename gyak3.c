#include <stdio.h>
#include <math.h>

// Síkpont típus
typedef struct {
    double x;
    double y;
} Síkpont;

// Kör típus
typedef struct {
    Síkpont középpont;
    double sugár;
} Kör;

// Négyzet típus
typedef struct {
    Síkpont balFelső;
    double oldalhossz;
} Négyzet;

// Két pont távolságának számítása
double tavolsag(Síkpont p1, Síkpont p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Pont és kör helyzete
const char* pontEsKorHelyzete(Síkpont pont, Kör kor) {
    double t = tavolsag(pont, kor.középpont);

    if (fabs(t - kor.sugár) < 1e-9) {
        return "A pont a körvonalon van.";
    } else if (t < kor.sugár) {
        return "A pont a körvonalon belül van.";
    } else {
        return "A pont a körvonalon kívül van.";
    }
}

// Négyzet középpontjának számítása
Síkpont negyzetKozeppontja(Négyzet negyzet) {
    Síkpont középpont;
    középpont.x = negyzet.balFelső.x + negyzet.oldalhossz / 2.0;
    középpont.y = negyzet.balFelső.y - negyzet.oldalhossz / 2.0;
    return középpont;
}

int main() {
    // a) Két síkpont távolsága
    Síkpont p1 = {0.0, 0.0};
    Síkpont p2 = {3.0, 4.0};
    printf("A ket pont tavolsaga: %.2f\n", tavolsag(p1, p2));

    // b) Pont és kör helyzete
    Síkpont pont = {1.0, 1.0};
    Kör kor = {{0.0, 0.0}, 2.0};
    printf("%s\n", pontEsKorHelyzete(pont, kor));

    // c) Négyzet középpontja
    Négyzet negyzet = {{0.0, 4.0}, 4.0};
    Síkpont kozeppont = negyzetKozeppontja(negyzet);
    printf("A negyzet kozeppontja: (%.2f, %.2f)\n", kozeppont.x, kozeppont.y);

    return 0;
}
