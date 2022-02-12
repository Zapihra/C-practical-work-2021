/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: Harjoitustyö Perustaso
 * Tekijä: Iida Vaaja
 * Opiskelijanumero: 606562
 * Päivämäärä: 14.3.21
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 * geeksforgeeks.org, Tomi Enberg - neuvoja, Rami Saarivuori Assari- neuvoja, opinto-opas, 
 */
/*******************************************************************/

#ifndef ali2_h
#define ali2_h
#include "paaohjelma.h"
#include "ali1.h"

void askName(char name[]);
void writeFile(char name[], chart lines[]);
void printInformation(chart lines[]);
Info *freeMemory(Info *start);
void alustus(chart Alltasks[]);
#endif