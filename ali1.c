/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: Harjoitustyö Perustaso
 * Tekijä: Iida Vaaja
 * Opiskelijanumero: 606562
 * Päivämäärä: 14.3.21
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 * geeksforgeeks.org, Tomi Enberg - neuvoja, Rami Saarivuori: Assari- neuvoja, opinto-opas
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali2.h"
#include <time.h>
#include "ali1.h"
#define max 60


Info *readFile(char name[], Info * start) {
    int end[3], begin[3];
    FILE *reading;
    Info *new = NULL, *point = start;
    int i = 0; 
    char memory[max];

    if ((reading = fopen(name, "r")) == NULL) {
        printf("Tiedoston lukeminen epäonnistui\n");
        exit(1);
    }
    
    fgets(memory, max, reading); //otsikko

    while ((fgets(memory, max, reading)) != NULL) {

        if ((new = (Info*)malloc(sizeof(Info))) == NULL) {
            printf("Muistinvaraus epäonnistui\n");
            exit(1);
        }

        if ((new->date = (struct tm*)malloc(sizeof(struct tm))) == NULL) {
            printf("Muistinvaraus epäonnistui\n");
            exit(1);
        }

        i++; // counts the amount of returned tasks
        
        new->date->tm_mday = atoi(strtok(memory, "/"));
        new->date->tm_mon = atoi(strtok(NULL, "/"));
        new->date->tm_year = atoi(strtok(NULL, " "));
        new->date->tm_hour = atoi(strtok(NULL, ":"));
        new->date->tm_min = atoi(strtok(NULL, ";"));
        strcpy(new->task, strtok(NULL, ";"));
        new->taskId = atoi(strtok(NULL, ";"));
        new->returnerId = atoi(strtok(NULL, "\n"));

        new -> Next = NULL;
        
        if (start == NULL) {
            start = new;
            
        }
        
        else {
            point = start;
            while (point->Next != NULL) {
                point = point-> Next;
            }
            point ->Next = new;
            
        }
       
    }
    fclose(reading);
    
    point = start;

    for(int j = 0; j < i; j++) {

        int year = point->date->tm_year;
        int month = point->date->tm_mon;
        int day = point->date->tm_mday;

        if (j == 0) {
            begin[0] = day;
            begin[1] = month;
            begin[2] = year;
            end[0] = day;
            end[1] = month;
            end[2] = year;
        }
        else {
            
            if (begin[2] > year){
                begin[2] = year;
                begin[1] = month;
                begin[0] = day;
            }
            else if (begin[1] > month && begin[2] == year) {
                begin[1] = month;
                begin[0] = day;
            }
            else if (begin[0] > day && begin[1] == month && begin[2] == year) {
                begin[0] = day;
            }

            if (end[2] < year) {
                end[2] = year;
                end[1] = month;
                end[0] = day;
            }
            else if (end[1] < month && end[2] == year) {
                end[1] = month;
                end[0] = day;
            }
            else if (end[0] < day && end[1] == month && end[2] == year) {
                end[0] = day;
            }
            
        }
        point = point ->Next;
    }
    printf("Yhteensä %d palautusta %02d.%02d.20%d - %02d.%02d.20%d väliseltä ajalta.\n", i, begin[0], begin[1], begin[2], end[0], end[1], end[2]);

    return start;
} 

void analiyseInformation(Info *start, chart Alltasks[]) {
    Info *point = start;
    char taskNow[20];
    int i = 0;
    int j = 0;
    int TaskIdNow;
    
    while(point != NULL) {
        strcpy(taskNow, point->task);
        TaskIdNow = point->taskId;
        if(strcmp(Alltasks[TaskIdNow -1].taskName, taskNow) != 0 ){
            strcpy(Alltasks[TaskIdNow -1].taskName, taskNow);
            Alltasks[TaskIdNow -1].amout += 1;
            j++; //montako uutta tehtävää
        }
        else {
            Alltasks[TaskIdNow-1].amout += 1;
        }
        i++; // montako tehtävää yhteensä
        point = point ->Next;
    }
    printf("Palautuksia oli yhteensä %d, %d eri tehtävässä, keskimäärin %d per tehtävä.\n", i, j, i/j);
}