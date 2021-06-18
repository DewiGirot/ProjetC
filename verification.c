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
*  Nom du fichier :  verification.c                                           *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "verification.h"

int verificationLongueurTexte(char texte[]){
	if (strlen(texte) >= 100) {
                return -1 ;
        }
        return 1;
}

int verificationCode (int clef) {
        if (clef>25 || clef<1  ) {
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

int verificationCaracteresSpeciaux (char texteATester[]) { 
	for(int i = 0; i < strlen(texteATester); i++){
		if(isalpha(texteATester[i]) || texteATester[i] != ' '){
			return 1;
		}
	}
	return -1;
}