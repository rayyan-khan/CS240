#include "header.h"

void readpatientrec(char *);
void agematch(unsigned short);
void purduematch(bool x);
void minmaxagematch(char c);

patient_t *first_patient;

int main(int argc, char * argv[]) {
    first_patient = (patient_t *)malloc(sizeof(patient_t));
    char *filename = argv[1];
    char buf[100];

    //printf("filename: %s\n", filename);
    readpatientrec(filename);

    patient_t *patient1 = (patient_t *)malloc(sizeof(patient_t));
    *patient1 = *first_patient;
    int i = 0;
    /*while(patient1->next != NULL) {
        printf("%d\n", i++);
        patient1 = patient1->next;
    }*/

    while(1) {
        printf(">");
        
        // read user command
	    fgets(buf, 100, stdin);

        if(buf[0] == 'a' && buf[1] == ' ') {
            int index = 2;
            int i = 0;
            char x[5];

            while(buf[index] != ' ' && buf[index] != '\n'&& buf[index] != '\0') {
                x[i++] = buf[index++];
            }
            unsigned short y = (unsigned short)atoi(x);
            agematch(y);
        }
        else if(buf[0] == 'p' && buf[1] == ' ') {
            bool b;
            if(buf[2] != '1' && buf[2] != '0') {
                printf("Argument for p must be 1 or 0, not %c\n", buf[2]);
                continue;
            }
            if(buf[2] == '1') {
                b = 1;
            }
            else if(buf[2] == '0') {
                b = 0;
            }
            purduematch(b);
        }
        else if(buf[0] == 'm' || buf[0] == 'M') {
            minmaxagematch(buf[0]);
        }
        else if(buf[0] == 'q') {
            
            // Exit program when 'q' is entered
            printf("Exiting program...\n");
            exit(0);
        }
        else {
            printf("No valid argument. Exiting program.\n");
            exit(1);
        }

    }
}

