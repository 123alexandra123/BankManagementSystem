#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editareCont()
{
    int optiune;
    int poz_cont[100];
    int contor = 0, optiune_cont;
    printf("Ai ales optiunea de editare a contului.\n\n");
    printf("Acestea sunt conturile dumneavoastra.\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < size_vector_conturi; i++)
        if (strcmp(conturi[i].nume, nume) == 0 && strcmp(conturi[i].prenume, prenume) == 0)
        {
            poz_cont[contor] = i;
            contor++;
            char mon[5];
            if(conturi[i].moneda==0)
                strcpy(mon,"RON");
            else if (conturi[i].moneda==1)
                strcpy(mon,"EURO");
            else if (conturi[i].moneda==2)
                strcpy(mon,"USD");
            else
            {
                system("cls");
                printf("Moneda indisponibila, va rugam incercati din nou.");
                return;
            }



            printf("CONT %d - IBAN: %s, Moneda: %s, Valuta: %f\n", contor, conturi[i].iban,mon,conturi[i].valuta);
        }

    printf("-1. Pentru revenirea la meniul principal\n\n");
    printf("Ce cont doriti sa modificati?\n");
    scanf("%d", &optiune_cont);

    if (optiune_cont == -1)
    {
        system("cls");
        return;
    }
    else if (optiune_cont > contor || optiune_cont <= 0)
    {
        system("cls");
        printf("Nu exista acest cont inregistrat pe numele dumneavoastra.\nVa rugam incercati din nou: \n\n");
        return;
    }
    else
    {
        system("cls");
        printf("Ai ales sa editezi contul tau numarul %d.\n\n", optiune_cont);
        printf("Ce doriti sa editati la contul dumneavoastra?\n");
        printf("--------------------------------------------\n");
        printf("1. IBAN\n");
        printf("2. VALUTA\n");
        printf("3. MONEDA\n");
        printf("-1. Pentru revenirea la meniul principal\n\n");
        printf("Alegeti una dintre optiunile de mai sus: ");
        scanf("%d", &optiune);
        printf("\n");

        char newIban[50];
        int ibanUnic;

        switch (optiune)
        {
        case 1:
            do
            {
                printf("Ati ales sa editati IBAN-UL\n");
                printf("Introduceti noul IBAN: ");
                scanf("%s", newIban);

                ibanUnic = uniqueIban(newIban);

                if (ibanUnic)
                    strcpy(conturi[poz_cont[optiune_cont - 1]].iban, newIban);

            }
            while (!ibanUnic);

            break;
        case 2:
            printf("Ati ales sa editati valuta\n");
            printf("Introduceti noua valoare: ");
            scanf("%f", &conturi[poz_cont[optiune_cont - 1]].valuta);
            break;
        case 3:
            printf("Ati ales sa editati moneda\n");
            printf("Alegeti noua moneda (0 pentru RON, 1 pentru EURO, 2 pentru USD): ");
            int moneda_veche = conturi[poz_cont[optiune_cont - 1]].moneda;
            scanf("%d", (int*)&conturi[poz_cont[optiune_cont - 1]].moneda);

            if (conturi[poz_cont[optiune_cont - 1]].moneda != moneda_veche)
            {
                float valoare_veche = conturi[poz_cont[optiune_cont - 1]].valuta;
                conturi[poz_cont[optiune_cont - 1]].valuta = conversie_valuta(valoare_veche, moneda_veche, conturi[poz_cont[optiune_cont - 1]].moneda);
            }

            break;
        case -1:
            system("cls");
            return;
        default:
            system("cls");
            printf("Optiune invalida.\nVa rugam alegeti alta actiune: \n\n");
            return;
        }
    }


    FILE *fisier = fopen("datee.txt", "w");
    if (fisier == NULL)
    {
        printf("Eroare la deschiderea fisierului.");
        exit(1);
    }

    fprintf(fisier, "NUME, PRENUME, IBAN, MONEDA, VALUTA\n");
    for (int i = 0; i < size_vector_conturi; i++)
    {
        fprintf(fisier, "%s, %s, %s, ", conturi[i].nume, conturi[i].prenume, conturi[i].iban);
        switch (conturi[i].moneda)
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
    system("cls");
    printf("\nModificarea contului a fost salvata cu succes!\n\n");
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
