//Write your code in this file
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEVER 5
#define NUM_PROV 13

void capitalize(char* name) {
    name[0] = toupper(name[0]);
}


float beräkna_medel(int resultat[], int antal) {
    int summa = 0;
    for (int i = 0; i < antal; i++) {
        summa += resultat[i];
    }
    return (float)summa / antal;
}

int main() {
    char namn[NUM_ELEVER][11];       
    int poäng[NUM_ELEVER][NUM_PROV];
    float medel[NUM_ELEVER];

  
    for (int i = 0; i < NUM_ELEVER; i++) {
        scanf("%s", namn[i]);
        for (int j = 0; j < NUM_PROV; j++) {
            scanf("%d", &poäng[i][j]);
        }
        medel[i] = beräkna_medel(poäng[i], NUM_PROV);
    }

 
    int bäst_index = 0;
    for (int i = 1; i < NUM_ELEVER; i++) {
        if (medel[i] > medel[bäst_index]) {
            bäst_index = i;
        }
    }

    capitalize(namn[bäst_index]);
    printf("%s\n", namn[bäst_index]);

    float total_medel = 0;
    for (int i = 0; i < NUM_ELEVER; i++) {
        total_medel += medel[i];
    }
    total_medel /= NUM_ELEVER;


    for (int i = 0; i < NUM_ELEVER; i++) {
        if (medel[i] < total_medel) {
            capitalize(namn[i]);
            printf("%s\n", namn[i]);
        }
    }

    return 0;
}
