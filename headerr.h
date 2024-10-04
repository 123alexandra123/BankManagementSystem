#ifndef HEADERR_H_INCLUDED
#define HEADERR_H_INCLUDED

#include <stdio.h>

//tipurile de monedă
enum bani {
    RON,
    EURO,
    USD
};

//struct pt conturi
struct cont {
    char nume[30];
    char prenume[30];
    char iban[50];
    enum bani moneda;
    float valuta;
};

// variabile globale
extern int ok;
extern char nume[100];
extern char prenume[100];
extern struct cont conturi[100];
extern int size_vector_conturi;

//funcții
void afisareMeniu();
void prelucrare_date_fisier(FILE* citire_din_fisier);
float conversie_valuta(float valoare, enum bani moneda_sursa, enum bani moneda_destinatie);
int uniqueIban(const char *newIban);
int login();
void creareCont(int argc, char* argv[]);
void editareCont();
void stergereCont();
void vizualizareCont();
void efectuareTranzactii();



#endif // HEADERR_H_INCLUDED
