#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void vizualizareCont()
{
    char bani[5];
    int poz_cont[100];
    int contor=0,optiune_cont;

    printf("Ai ales optiunea de vizualizare a contului.\n\n");
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
    printf("-1. Pentru revenirea la meniul principal");
    printf("\n\n");
    printf("Alegeti unul din conturile dumneavoastra: ");
    scanf("%d",&optiune_cont);


    if(optiune_cont==-1)
    {
        system("cls");
    }
    else if(optiune_cont>contor || optiune_cont<=0)
    {
        system("cls");
        printf("Nu exista acest cont inregistrat pe numele dumneavoastra.\nVa rugam alegeti alta actiune: \n\n");
    }

    else
    {
        system("cls");
        printf("Ai ales contul tau numarul %d\n\n",optiune_cont);
        printf("CONTUL MEU %d\n",optiune_cont);
        printf("------------------------------\n");
        printf("IBAN: %s \n", conturi[poz_cont[optiune_cont-1]].iban);
        switch(conturi[poz_cont[optiune_cont-1]].moneda)
        {
        case 0:
            strcpy(bani,"RON");
            break;
        case 1:
            strcpy(bani,"EURO");
            break;
        case 2:
            strcpy(bani,"USD");
            break;
        }

        printf("Moneda: %s\n", bani);
        printf("Valuta: %f\n", conturi[poz_cont[optiune_cont-1]].valuta);
        printf("\n\n");

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
}
