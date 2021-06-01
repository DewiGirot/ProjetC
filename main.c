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
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int verificationCode (int clef);
int verificationChiffrage (int chiffrage);
int verificationCaracteresSpeciaux (char texte []);
void cesar (char texte[], int clef, int chiffrage);


void main () {

        char texte[100];
        int chiffrage;
        int clef;

        printf("Entrez votre message, attention il ne doit pas contenir des caractères spéciaux et ne pas doit dépasser les 100 caractères : \n     ");
        scanf("%s",&texte);
        while (verificationCaracteresSpeciaux(texte) == 1) {
        	printf("Erreur veuillez réessayer : \n     ");
        	scanf("%s",&texte);
        	printf("\n",texte);
	}
        

        printf("Entrez votre clef : \n     ");
        scanf("%d",&clef);
        while ( verificationCode(clef) == -1 ) {
		printf("Erreur veuillez réessayer : \n     ");
		scanf("%d",&clef);
	}
	
        printf("Voulez vous chifrer ou déchiffrer le message ? ( 1 pour chiffrer et 0 pour déchiffrer)\n     ");
        scanf("%d",&chiffrage);
        while ( verificationChiffrage(chiffrage) == -1 ) {
		printf("Erreur veuillez réessayer : \n     ");
		scanf("%d",&chiffrage);
	}
        
        printf("message : \n     ");
        cesar(texte,clef,chiffrage);
        printf("%s\n",texte);
        

}


int verificationCode (int clef) {
        if (clef>26 || clef<1  ) {
                return -1 ;
        }
        return 1;
}

int verificationChiffrage(int chiffrage) {
	if (chiffrage == 1 || chiffrage == 0)  {
		return 1;
	}
	return -1;
}


void cesar (char texte[],int clef,int chiffrage) {
    for(int i=0 ; i<strlen(texte) ; i++)
    	if ( chiffrage == 1 )
            texte[i] = 'a' + ((texte[i] - 'a') + clef)%26;
        else {
        	if(('a' + ((texte[i] - 'a') - clef)) < 'a')
        		texte[i] = 'z' + 1 + ((texte[i] - 'a') - clef);
        	else
        		texte[i] = 'a' + ((texte[i] - 'a') - clef);
        	
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