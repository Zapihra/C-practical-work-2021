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
#include <string.h>
#include <stdlib.h>
#include "ali1.h"
#include <time.h>
#include "ali2.h"
#include "paaohjelma.h"


int main(void){
    int i = 1;
    char name[20];
    Info * start = NULL;
    char c;
    chart lines[60];

    alustus(lines);
    while(i != 0) {
        printf("1) Lue tiedosto\n2) Analysoi tiedot\n");
        printf("3) Tulosta tulokset\n0) Lopeta\nValintasi: ");
        scanf("%d", &i);
        
        
        if(i == 1){
            if(start != NULL) {
                start = freeMemory(start);
            }
            
            askName(name);
            start = readFile(name, start);
            printf("\n");
        }
        else if(i == 2) {
            if (start == NULL) {
                printf("Ei analysoitavaa, lue ensin palautustiedosto.\n");
            }
            else {
                alustus(lines);
                analiyseInformation(start, lines);
            }
            printf("\n");
        }
        else if(i == 3) {
            if (lines[0].amout == 0 && strcmp(lines[0].taskName, "Tyhjä") == 0) {
                printf("Ei tulostettavaa, analysoi ensin palautustiedosto.\n");
            }            
            else {
                printf("Tulosta tiedostoon (k/e): ");
                scanf(" %c", &c);
                getchar(); 
                switch (c)
                {
                case 'k':
                    askName(name);
                    writeFile(name, lines);
                    break;
            
                default:
                    printInformation(lines);
                    break;

                }
            }
            printf("\n");
        }
        else if(i == 0) {
            start = freeMemory(start);

            printf("Kiitos ohjelman käytöstä.\n\n");
        }
        else {
            printf("Tuntematon valinta, yritä uudestaan.\n\n");
            
        }
    }

}