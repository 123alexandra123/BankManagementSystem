#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void creareCont(int argc, char *argv[])
{
    printf("Ai ales optiunea de creare a unui cont nou.\n\n");

    strcpy(conturi[size_vector_conturi].nume, argv[1]);
    strcpy(conturi[size_vector_conturi].prenume, argv[2]);

    char newIban[50];
    int ibanUnic;

    do
    {
        printf("Introduceti IBAN-ul pentru noul cont: ");
        scanf("%s", newIban);

        ibanUnic = uniqueIban(newIban);

        if (ibanUnic)
            strcpy(conturi[size_vector_conturi].iban, newIban);

    }
    while (!ibanUnic);


    printf("Alegeti moneda pentru noul cont (0 pentru RON, 1 pentru EURO, 2 pentru USD): ");
    scanf("%d", (int*)&conturi[size_vector_conturi].moneda);
    if(conturi[size_vector_conturi].moneda !=0 &&
    conturi[size_vector_conturi].moneda !=1 &&
            conturi[size_vector_conturi].moneda !=2)
    {
        system("cls");
        printf("Moneda indisponibila. Va rugam reluati actiunea.\n\n");
        return;
    }

    printf("Introduceti valuta pentru noul cont: ");
    scanf("%f", &conturi[size_vector_conturi].valuta);

    size_vector_conturi++;

    FILE *fisier = fopen("datee.txt", "a");
    if (fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(1);
    }

    fprintf(fisier, "%s, %s, %s, ", conturi[size_vector_conturi-1].nume, conturi[size_vector_conturi-1].prenume, conturi[size_vector_conturi-1].iban);
    switch (conturi[size_vector_conturi-1].moneda)
    {
    case RON:
        fprintf(fisier, "RON, ");
        break;
    case EURO:
        fprintf(fisier, "EURO, ");
        break;
    case USD:
        fprintf(fisier, "USD, ");
        break;
    }
    fprintf(fisier, "%f\n", conturi[size_vector_conturi-1].valuta);

    fclose(fisier);

    printf("Contul a fost creat cu succes!\n\n");
    int alta_actiune;
        printf("Doriti sa efectuati alta actiune?\n");
        printf("1.Da, inapoi la meniul principal.\n");
        printf("2.Nu, inchide aplicatia.\n");
        printf("-----------------------------\n");
        printf("Alegeti optiunea dumneavoastra:");
        scanf("%d",&alta_actiune);
        if(alta_actiune==1)
        {
            ok=1;
            system("cls");
        }
        else if(alta_actiune==2)
        {
            ok=0;
            system("cls");
            printf("Va multumim pentru colaborare. La revedere!\n");
        }
        else
        {
            system("cls");
            printf("Comanda incorecta. Va rugam reluati procesul.\n\n");
        }
}

