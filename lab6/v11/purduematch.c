#include "header.h"

extern patient_t *first_patient;

void purduematch(bool x) {
    patient_t *temp = first_patient;

    int match = 0;

    while(temp != NULL) {
        if(temp->purduegraduate == x && temp->weight != 0) {
            match = 1;
            printf("%d %s %s %d %d %d %d\n", temp->age, temp->pname.first, 
            temp->pname.last, temp->pheight.feet, temp->pheight.inches, 
            temp->weight, temp->purduegraduate);
        }
        temp = temp->next;
    }

    if(match == 0) {
        printf("No matches were found.\n");
    }
}