#include "header.h"

extern patient_t *first_patient;
void line_to_patient(char *);

void readpatientrec(char * filename) {
    
    unsigned short tempage;
    char tempfirst[21];
    char templast[21];
    int tempfeet;
    int tempinches;
    unsigned int tempweight;
    int temppurduegraduate;

    FILE *patient_data = fopen(filename, "r"); 
    if(patient_data == NULL) {
        printf("Problem opening file. Ending program.\n");
        exit(1);
    }

    patient_t *temp_patient = first_patient;
    int patient_count = 0;
    
    while (fscanf(patient_data, "%hu %s %s %d %d %u %d", &tempage, tempfirst, templast, &tempfeet, &tempinches, &tempweight, &temppurduegraduate) != EOF) {

        patient_count++;

        temp_patient->pname.first = malloc(strlen(tempfirst));
        temp_patient->pname.last = (char *)malloc(sizeof(char) * strlen(templast));
        strcpy(temp_patient->pname.first, tempfirst);
        strcpy(temp_patient->pname.last, templast); 
        temp_patient->pheight.feet = tempfeet;
        temp_patient->pheight.inches = tempinches;
        temp_patient->age = tempage;
        temp_patient->weight = tempweight;
        temp_patient->purduegraduate = temppurduegraduate;

        /*printf("FIRST_PATIENT\nFirst name: %s %s\n Height: %d feet %d inches\n Age: %u\n Weight: %u\n Purdue Grad: %d\n",
        first_patient->pname.first, first_patient->pname.last, first_patient->pheight.feet, 
        first_patient->pheight.inches, first_patient->age, first_patient->weight, first_patient->purduegraduate);
        
        printf("TEMP_PATIENT\nFirst name: %s %s\n Height: %d feet %d inches\n Age: %u\n Weight: %u\n Purdue Grad: %d\n",
        temp_patient->pname.first, temp_patient->pname.last, temp_patient->pheight.feet, 
        temp_patient->pheight.inches, temp_patient->age, temp_patient->weight, temp_patient->purduegraduate);*/

        temp_patient->next = (patient_t *)malloc(sizeof(patient_t));
        temp_patient = temp_patient->next;
    }

    temp_patient = NULL;
    free(temp_patient);

    fclose(patient_data);

}
