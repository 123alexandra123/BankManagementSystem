#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stergereCont()
{
    int optiune,nr_cont=0;
    printf("Ati ales optiunea de stergere a contului.\n\n");

    printf("Acestea sunt conturile dumneavoastra:\n");
    for(int i = 0; i < size_vector_conturi; i++)
    {
        if(strcmp(nume, conturi[i].nume) == 0 && strcmp(prenume, conturi[i].prenume) == 0)
        {
            nr_cont++;
            printf("CONT %d - IBAN: %s\n", nr_cont, conturi[i].iban);
        }
    }

    int cont_ales;
    printf("\nAlege numarul contului pe care doresti sa-l stergi: ");
    scanf("%d", &cont_ales);


    if (cont_ales < 1 || cont_ales > nr_cont)
    {
        system("cls");
        printf("Numarul contului ales de dumneavoastra este invalid.\n");
        printf("Va rugam incercati din nou.\n\n");
        return;
    }

    system("cls");
    printf("Sunteti sigur ca doriti sa stergeti acest cont?\n");
    printf("1.Da.\n2.Nu, inapoi la meniul principal.\n");
    scanf("%d", &optiune);

    if (optiune == 1)
    {
        int index = 0;
        for(int i = 0; i < size_vector_conturi; i++)
        {
            if(strcmp(nume, conturi[i].nume) == 0 && strcmp(prenume, conturi[i].prenume) == 0)
            {
                index++;
                if (cont_ales == index)
                {
                    for(int j = i; j < size_vector_conturi - 1; j++)
                    {
                        conturi[j] = conturi[j + 1];
                    }
                    break;
                }
            }
        }
        size_vector_conturi--;


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

        system("cls");
        printf("Contul a fost sters cu succes!\n\n");
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
    else
    {
        system("cls");
        printf("Operatia de stergere a contului a fost anulata.\n\n");
    }
}
