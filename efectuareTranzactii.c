#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void efectuareTranzactii()
{
    printf("Ai ales optiunea de efectuare a tranzactiilor.\n");


    int poz_cont[100], contor = 0;
    printf("Conturile dumneavoastra sunt:\n");
    printf("-----------------------------\n");
    for(int i=0; i<size_vector_conturi; i++)
    {
        if(strcmp(conturi[i].nume,nume)==0  &&  strcmp(conturi[i].prenume,prenume)==0)
        {
            poz_cont[contor]=i;
            contor++;
        }
    }
    for(int i = 0; i < contor; i++)
    {
        printf("CONT %d - IBAN: %s\n", i + 1, conturi[poz_cont[i]].iban);
    }

    printf("Alegeti contul din care doriti sa efectuati tranzactia: ");
    int optiune_cont;
    scanf("%d", &optiune_cont);
    system("cls");

    if(optiune_cont <= 0 || optiune_cont > contor)
    {
        printf("Numarul contului ales este invalid.\n\n");
        return;
    }

    int cont_sursa_index = poz_cont[optiune_cont - 1];


    printf("Catre ce cont doriti sa virati banii?\n");
    for(int i = 0; i < size_vector_conturi; i++)
    {
        if(i != cont_sursa_index)
        {
            printf("%d. %s %s - IBAN: %s\n", i + 1, conturi[i].nume, conturi[i].prenume, conturi[i].iban);
        }
    }

    int optiune_cont_destinatie;
    printf("Alegeti contul destinatie: ");
    scanf("%d", &optiune_cont_destinatie);
    optiune_cont_destinatie--;

    if(optiune_cont_destinatie < 0 || optiune_cont_destinatie >= size_vector_conturi || optiune_cont_destinatie == cont_sursa_index)
    {
        system("cls");
        printf("Contul destinatie ales este invalid.\n\n");
        return;
    }


    float suma;
    printf("Introduceti suma pentru tranzactie: ");
    scanf("%f", &suma);

    if(suma > conturi[cont_sursa_index].valuta)
    {
        system("cls");
        printf("Fonduri insuficiente in contul sursa.\n");
        printf("Va rugam incercati din nou\n\n");
        return;
    }
    conturi[cont_sursa_index].valuta -= suma;

    if (conturi[cont_sursa_index].moneda != conturi[optiune_cont_destinatie].moneda)
        suma = conversie_valuta(suma, conturi[cont_sursa_index].moneda, conturi[optiune_cont_destinatie].moneda);


    conturi[optiune_cont_destinatie].valuta += suma;

    FILE *fisier = fopen("datee.txt", "w");
    if(fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(1);
    }

    fprintf(fisier, "NUME, PRENUME, IBAN, MONEDA, VALUTA\n");
    for(int i = 0; i < size_vector_conturi; i++)
    {
        fprintf(fisier, "%s, %s, %s, ", conturi[i].nume, conturi[i].prenume, conturi[i].iban);
        switch(conturi[i].moneda)
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
        fprintf(fisier, "%f\n", conturi[i].valuta);
    }
    fclose(fisier);

    printf("Tranzactie efectuata cu succes!\n\n");
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
