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

#ifndef ali1_h
#define ali1_h
#include "paaohjelma.h"

Info *readFile(char name[20], Info *start);
void writeFile();
void analiyseInformation(Info *start, chart Alltasks[]);

#endif