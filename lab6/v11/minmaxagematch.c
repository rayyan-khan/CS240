#include "header.h"

extern patient_t *first_patient;

void minmaxagematch(char c) {
    
    patient_t *temp = first_patient;

    if(c == 'm') {
        // find min
        int min = 100;
        while(temp->next != NULL) {
            if((int)temp->age < min && (int)temp->age != 0 && (int)temp->weight != 0) {
                min = (int)temp->age;
            }
            temp = temp->next;
        }

        
        patient_t *temp = first_patient;
        while(temp != NULL) {
            if((int)temp->age == min) {
                printf("%d %s %s %d %d %d %d\n", temp->age, temp->pname.first, 
                temp->pname.last, temp->pheight.feet, temp->pheight.inches, 
                temp->weight, temp->purduegraduate);
            }
            temp = temp->next;
        }
    }
    else {
        // find max
        int max = 0;
        while(temp != NULL) {
            if((int)temp->age > max && temp->pname.first != NULL) {
                max = (int)temp->age;
            }
            temp = temp->next;
        }
        
        patient_t *temp = first_patient;
        while(temp != NULL) {
            if((int)temp->age == max) {
                printf("%d %s %s %d %d %d %d\n", temp->age, temp->pname.first, 
                temp->pname.last, temp->pheight.feet, temp->pheight.inches, 
                temp->weight, temp->purduegraduate);
            }
            temp = temp->next;
        }
    }
}