#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#include "dico.h"

int piocherMot(char *motPioche);
int gagne(int lettreTrouvee[], int tailleMot);
int rechereLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();


int main()
{
    int i = 0;
    char motSecret[100] = {0};
    char lettre = 0;
    int nombreEssai = 0;
    int* lettreTrouvee = NULL;
    char lettreEssayee[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int lettreEssayeeBool[26] = {0};
    int tailleMot = 0;
    int rejouer = 1;
    int nombreJoueur = 0;
    

    do
    {
        int nombreEssai = 10;                      //reinitialisation du nombre d'essai ainsi que tu tableau des lettres deja essaye
        int lettreEssayeeBool[26] = {0};


        printf("bienvenue dans le jeu.\n\n");
        printf("Combien de joueur etes vous? \n\n");
        scanf("%d", &nombreJoueur);
        if (nombreJoueur == 1)
        {
           if(!piocherMot(motSecret))
           exit (0);
        }
        if (nombreJoueur == 2)
        {
            printf("Veuillez rentrer le mot a faire deviner: \n");
            scanf("%s", motSecret);
            tailleMot = strlen(motSecret);
            for (size_t i = 0; i < tailleMot; i++)
            {
                motSecret[i] = toupper(motSecret[i]);
            }
        }
        tailleMot = strlen(motSecret);
        //initialisation du tableau des lettres trouvees 
        lettreTrouvee = malloc(tailleMot * sizeof(int));
        if (lettreTrouvee == NULL)
            exit(0);

        for ( i = 0; i < tailleMot; i++)
        {
            lettreTrouvee[i] = 0;
        }
    
    
        while (nombreEssai > 0 && !gagne(lettreTrouvee, tailleMot))
        {
        printf("\nIl vous reste %d essais\n\n", nombreEssai);
        for (size_t i = 0; i < tailleMot; i++)
         {
            if(lettreTrouvee[i])
            {
                printf("%c", motSecret[i]);
            }
            else
            {
                printf("*");
            }
         }

         printf("\n\nVeuillez entrer une lettre :");
         lettre = lireCaractere(); //lecture du caractere 
         liste_essai(lettre, lettreEssayee, lettreEssayeeBool); // liste de lettres essayees

            if(!rechereLettre(lettre, motSecret, lettreTrouvee))
            {  
                int p = 0;
                nombreEssai--;
                printf("\n Voici les lettres essayees :"); // Lettres essayees
                for (size_t p = 0; p < 24; p++)
                {
                    if(lettreEssayeeBool[p])
                    {
                        printf("%c,", lettreEssayee[p]);
                    }
                }
            }



        }
        //Condition de fin de jeu.
        if(nombreEssai == 0)
            {
                printf("\n\nVous avez perdu! Le mot etait : %s\n", motSecret);
                printf("voulez vous rejouez ? 1 oui 2 non");
                scanf("%d", &rejouer);

            }
        if(gagne(lettreTrouvee, tailleMot))
            {
                printf("\n\nFelicitation! il vous restait %d essais!\n", nombreEssai);
                printf("voulez vous rejouez ? 1 oui 2 non");
                scanf("%d", &rejouer);
            }

    }while(rejouer == 1);

}

char lireCaractere()
{
    char caractere = 0;

    caractere = getchar();
    caractere = toupper(caractere);

    while (getchar() !='\n');
    return caractere;
}

int rechereLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i = 0;
    int bonnelettre = 0;
    for (size_t i = 0; motSecret[i] != '\0'; i++)
    {
        if(lettre == motSecret[i])
        {
            bonnelettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonnelettre;
}

int gagne(int lettreTrouvee[], int tailleMot)
{
    int i = 0;
    int gagne = 1;
    for (i = 0; i < tailleMot; i++)
    {
        if(lettreTrouvee[i] != 1)
        {
            gagne = 0;
        }
    }
    return gagne;
}


