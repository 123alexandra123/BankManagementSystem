#include "headerr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float conversie_valuta(float valoare, enum bani moneda_sursa, enum bani moneda_destinatie) {
    float rata_schimb = 1.0;
    switch (moneda_sursa) {
        case RON:
            if (moneda_destinatie == EURO)
                rata_schimb = 0.20; // 1 RON = 0.20 EURO
            else if (moneda_destinatie == USD)
                rata_schimb = 0.22; // 1 RON = 0.22 USD
            break;
        case EURO:
            if (moneda_destinatie == RON)
                rata_schimb = 4.98; // 1 EURO = 4.98 RON
            else if (moneda_destinatie == USD)
                rata_schimb = 1.08; // 1 EURO = 1.08 USD
            break;
        case USD:
            if (moneda_destinatie == RON)
                rata_schimb = 4.61; // 1 USD = 4.61 RON
            else if (moneda_destinatie == EURO)
                rata_schimb = 0.93; // 1 USD = 0.93 EURO
            break;
    }
    return valoare * rata_schimb;
}
