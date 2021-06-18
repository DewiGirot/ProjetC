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
#include "cesar.h"
#include "convertir.h"
#include "verification.h"

void main () {

        char texte[100];
        int chiffrage;
        int clef;

        printf("Entrez votre message, attention il ne doit pas contenir des caractères spéciaux et ne pas doit dépasser les 100 caractères : \n     ");
        fgets(texte,1024,stdin);
        //scanf("%s",&texte);
        
        while (verificationLongueurTexte(texte) == -1) {
        	printf("Erreur veuillez donnez un texte inférieur à 100 caractères : \n     ");
        	scanf("%s",&texte);
	}
	
	//convertirAccents(texte); ne marche pas
        
        while (verificationCaracteresSpeciaux(texte) == -1) {
        	printf("Erreur veuillez entrer un texte sans caractères spéciaux : \n     ");
        	scanf("%s",&texte);
	}

        printf("Entrez votre clef comprise entre 0 et 26 non compris : \n     ");
        scanf("%d",&clef);
        while ( verificationCode(clef) == -1 ) {
		printf("Erreur veuillez réessayer : \n     ");
		scanf("%d",&clef);
	}
	
        printf("Voulez vous chifrer ou déchiffrer le message ? (1 pour chiffrer et 0 pour déchiffrer)\n     ");
        scanf("%d",&chiffrage);
        while ( verificationChiffrage(chiffrage) == -1 ) {
		printf("Erreur veuillez saisir 1 pour chiffrer et 0 pour déchiffrer : \n     ");
		scanf("%d",&chiffrage);
	}
        
        char texte1[100]; // on sauvegarde le message original dans texte1
        strcpy(texte1, texte);
        printf("message : \n     ");
        cesar(texte,clef,chiffrage);
        printf("%s\n",texte);
        
        printf("Enregistrement des informations dans un txt\n");
        FILE* fichier = NULL;
    	fichier = fopen("enregistrement.txt", "a");
    	//sauvegarde des différentes informations obtenu par l'utilisateur dans le fichier texte enregistrement
                
    	fprintf(fichier,"\n---------------------------\n");
        fprintf(fichier," INFORMATIONS ENREGISTREES\n");
    	fprintf(fichier,"---------------------------\n");
       	fprintf(fichier,"\nMessage original : %s\n",texte1);
       	fprintf(fichier,"Clef / décalage : %d\n",clef);
       	if ( chiffrage == 1 ) 
        	fprintf(fichier,"Le message a été coder\n");
        else 
        	fprintf(fichier,"Le message a été décoder\n");
        fprintf(fichier,"Message obtenue : %s\n",texte);
        
}