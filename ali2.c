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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali2.h"


void askName(char name[]) {
    char help[20];
    printf("Anna tiedoston nimi: ");
    scanf("%s", help);
    strcpy(name, help);
}

Info *freeMemory(Info *start){
    Info *point = start;
    while (point != NULL) {
        start = point->Next;
        free(point->date);
        free(point);
        point = start;
    }
    start = NULL;
    return start;
}

void writeFile(char name[], chart lines[]) {
    FILE *writing;

    if((writing = fopen(name, "w")) == NULL) {
        printf("Tiedostoon kirjoittaminen epäonnistui");
        exit(1);
    }
    
    fprintf(writing, "Tehtävä;Lkm\n");
    for (int i = 0; i < 60; i++) {
        fprintf(writing, "%s;%d\n", lines[i].taskName, lines[i].amout);
    }
    fclose(writing);
}

void printInformation(chart lines[]) {

    printf("Tehtävä;Lkm\n");
    for (int i = 0; i <60; i++) {
        printf("%s;%d\n", lines[i].taskName, lines[i].amout);
    }
}

void alustus(chart Alltasks[]) {
    for (int k = 0; k < 60; k++) {
        Alltasks[k].amout = 0;
        strncpy(Alltasks[k].taskName, "Tyhjä",sizeof(Alltasks[k].taskName));
    }
}