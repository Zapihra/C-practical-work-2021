/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: Harjoitustyö Perustaso
 * Tekijä: Iida Vaaja
 * Opiskelijanumero: 606562
 * Päivämäärä: 14.3.21
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 * geeksforgeeks.org, Tomi Enberg - neuvoja, Rami Saarivuori Assari- neuvoja, opinto-opas
 */
/*******************************************************************/

#ifndef paaohjelma_h
#define paaohjelma_h
#include <time.h>

typedef struct CHART{
    char taskName[10];
    int amout;
} chart;

typedef struct INFO {
    struct tm *date;
    char task[10];
    int taskId;
    int returnerId;
    struct INFO *Next;
} Info;

#endif