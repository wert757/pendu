#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int piocherMot(char *motPioche)
{
    FILE* dictio = NULL;
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu;
    int difficultee = 0;
    printf("Selectionnez la difficultee 1) facile 2) medium 3) difficile");
    scanf("%d", &difficultee);
    if (difficultee == 1)
    {
        dictio = fopen("dictio_easy.txt", "r");
        printf("vous etes a facile");
    }
    else if (difficultee == 2)
    {
        dictio = fopen("dictio_medium.txt", "r");
        printf("vous etes a medium");
    }
    else if (difficultee == 3)
    {
        dictio = fopen("dictio_hard.txt", "r");
        printf("vous etes a difficile");
    }
    
    if(dictio == NULL)
    {
        printf("Impossible de charger le dictionnaire de mot");
        return 0;
    }
    do
    {
        caractereLu = fgetc(dictio);
        if(caractereLu == '\n')
            nombreMots++;
    } while (caractereLu != EOF);
    
    numMotChoisi =nombreAleatoire(nombreMots);

    rewind(dictio);
    while(numMotChoisi > 0)
    {
        caractereLu = fgetc(dictio);
        if(caractereLu == '\n')
            numMotChoisi--;
    }

    fgets(motPioche, 100, dictio);
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dictio);
        return 1;
    }

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return(rand() % nombreMax);
}

void liste_essai(char lettre, char lettreEssayee[], int lettreEssayeeBool[])
{
    int i = 0;
    for (size_t i = 0; lettreEssayee[i] != '\0'; i++)
    {
        if(lettre == lettreEssayee[i])
        {
            lettreEssayeeBool[i] = 1;
        }
    }
    
}
