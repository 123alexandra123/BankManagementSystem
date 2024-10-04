#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void prelucrare_date_fisier(FILE*citire_din_fisier)
{
    int contor=0;
    char data[200];
    fgets(data,200,citire_din_fisier);

    while(fgets(data,200,citire_din_fisier))
    {

        char *p=strtok(data,", ");
        strcpy(conturi[contor].nume,p);
        p=strtok(NULL,", ");
        strcpy(conturi[contor].prenume,p);
        p=strtok(NULL,", ");
        strcpy(conturi[contor].iban,p);
        p=strtok(NULL,", ");
        if(strcmp(p,"EURO")==0)
            conturi[contor].moneda=EURO;
        else if(strcmp(p,"RON")==0)
            conturi[contor].moneda=RON;
        else if(strcmp(p,"USD")==0)
            conturi[contor].moneda=USD;
        p=strtok(NULL,", ");
        conturi[contor].valuta=(atof)(p);
        contor++;

    }




    size_vector_conturi=contor;

}
