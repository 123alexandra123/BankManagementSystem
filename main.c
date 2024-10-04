#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerr.h"

int main(int argc, char * argv[])
{
    if (argc < 3)
        exit(1);

    strcpy(nume, argv[1]);
    strcpy(prenume, argv[2]);

    FILE *pointer_spre_fisier;
    pointer_spre_fisier = fopen("datee.txt", "r+");
    prelucrare_date_fisier(pointer_spre_fisier);
    fclose(pointer_spre_fisier);


    if(login()==0)
    {
        printf("Nu sunteti inregistrati in sistemul nostru.\n");
        printf("Doriti sa va creati un cont?\n");
        printf("1.Da\n2.Nu, inchide aplicatia.\n");
        int contnou;
        scanf("%d",&contnou);
        if(contnou==1)
        {
            system("cls");
            creareCont(argc,argv);
        }
        else if(contnou==2)
        {
            system("cls");
            printf("La revedere!");
            exit(2);
        }
        else
        {
            system("cls");
            printf("Comanda incorecta. Va rugam reluati procesul.\n");
        }
    }

    int optiune;

    do
    {
        afisareMeniu();
        scanf("%d", &optiune);
        system("cls");

        switch (optiune)
        {

        case 1:
            creareCont(argc,argv);
            break;
        case 2:
            editareCont();
            break;
        case 3:
            stergereCont();
            break;
        case 4:
            vizualizareCont();
            break;
        case 5:
            efectuareTranzactii();
            break;
        case 6:
            printf("La revedere!\n");
            break;
        default:
            printf("Optiune invalida. Te rog sa alegi din nou.\n\n");
        }

    }
    while (optiune != 6 && ok != 0);
    return 0;
}
