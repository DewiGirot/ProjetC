/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet :    3                                                         *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé :   Chiffrement de messages                                       *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : GIROT Déwi                                                   *
*                                                                             *
*  Nom-prénom2 :   BAUDRAND Paul-Alexandre                                    *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  main.c                                                   *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int verification (int c, int type);
int verificationCaracteresSpeciaux (char texte []);
void affichageVerification(int c, int type);
char cesar (char texte[], int clef);


void main () {

        char texte[100];
        int chiffrage;
        int clef;
        int type;

        printf("Entrez votre message, attention il ne doit pas contenir des caractères spéciaux et ne pas doit dépasser les 100 caractères : \n     ");
        scanf("%s",&texte);
        

        printf("Entrez votre clef : \n     ");
        scanf("%d",&clef);
        affichageVerification(clef,26);
        
	while (verificationCaracteresSpeciaux(texte) == 1) {
        	printf("Erreur, votre message possède des caractères spéciaux ! \n\n");
        	printf("Entrez une nouveau message : \n");
        	scanf("%s",&texte);
        	printf("\n",texte);
	}
    
        printf("Voulez vous chifrer ou dechiffrer le message ? ( 1 pour Oui et -1 pour Non)\n     ");
        scanf("%d",&chiffrage);
        affichageVerification(chiffrage,1);
        
        printf("message : \n     ");
        cesar(texte,3);
        printf("%s\n",texte);
        

}

int verification (int c, int type) {
        if (c>type || c<1  ) {
                return -1 ;
        }
        return 1;
}

void affichageVerification(int c, int type) {
    while ( verification(c , type) == -1 ) {
        printf("Erreur veuillez réessayer : \n");
        scanf("%d",&c);
    }
}

char cesar (char texte[],int clef) {
    	for ( int i = 0 ; i < strlen(texte) ; i++ ) {
       		texte[i] -= 'A';
       		printf("avant changement%d\n", texte[i]);		
       		texte[i] = (texte[i] + clef) %26 - 1;
       		texte[i] += 'A';
       		printf("après changement%d\n", texte[i]);
    	}
}

int verificationCaracteresSpeciaux (char texteATester[]) { 
	for(int i = 0; i < strlen(texteATester); i++){
		if(isalpha(texteATester[i]) == 0){
			return 1;
		}
	}
	return 0;
}