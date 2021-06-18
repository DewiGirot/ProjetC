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
*  Nom du fichier :  cesar.c                                                  *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "cesar.h"

void cesar (char texte[],int clef,int chiffrage) {
	
	for(int i=0 ; i<strlen(texte) ; i++){
	    	if ( chiffrage == 1 ){
			if ('a' <= texte[i] && texte[i] <= 'z') {
		    		texte[i] = 'a' + ((texte[i] - 'a') + clef)%26;
			}else if ('A' <= texte[i] && texte[i] <= 'Z'){
				texte[i] = 'A' + ((texte[i] - 'A') + clef)%26;
			}
			// pour les chiffres, mais on arrive pas à déchiffrer par la suite 
			/*else
		        	if ('0' <= texte[i] && texte[i] <= '9')
		            		texte[i] = '0' + ((texte[i] - '0') + clef)%10;	 	
	    		*/
		} else {
			if ('a' <= texte[i] && texte[i] <= 'z')
				if(('a' + ((texte[i] - 'a') - clef)) < 'a')
					texte[i] = 'z' + 1 + ((texte[i] - 'a') - clef);
				else 
					texte[i] = 'a' + ((texte[i] - 'a') - clef);
			else if ('A' <= texte[i] && texte[i] <= 'Z'){
				if(('A' + ((texte[i] - 'A') - clef)) < 'A')
					texte[i] = 'Z' + 1 + ((texte[i] - 'A') - clef);
				else
					texte[i] = 'A' + ((texte[i] - 'A') - clef);
			}
		}
	}       
}