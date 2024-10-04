#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int login()
{
    for(int i=0; i<size_vector_conturi; i++)
        if(strcmp(conturi[i].nume,nume)==0  &&  strcmp(conturi[i].prenume,prenume)==0)
            return 1;
    return 0;
}
