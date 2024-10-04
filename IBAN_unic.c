#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int uniqueIban(const char *newIban)
{
    for (int i = 0; i < size_vector_conturi; i++)
    {
        if (strcmp(conturi[i].iban, newIban) == 0)
        {
            printf("\nIBAN-ul introdus este indisponibil. Acest IBAN exista deja in fisierul nostru de date.\n");
            printf("Va rugam incercati din nou.\n\n");
            return 0;
        }
    }
    return 1;
}
