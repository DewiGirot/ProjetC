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
*  Nom du fichier :  convertir.c                                              *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "convertir.h"

void convertirAccents (char texte[]) {
	char Accents [] = 	"ÀÁÂÄÅàáâàäåÒÓÔÕÖØòóôõöøÈÉÊËèéêëÇçÌÍÎÏìíîïÙÚÛÜùúûüÿÑñ";
	char SansAccents [] = 	"AAAAAaaaaaaOOOOOOooooooEEEEeeeeCcIIIIiiiiUUUUuuuuyNn";
	for (int i=0 ; i<strlen(texte) ; i++) {
		for (int l=0 ; l<strlen(Accents) ; l++) {
			if (texte[i] == Accents[l])
				texte[i] = SansAccents[l];
			
				/*switch(i)
					{
					case 0:case 1:case 2:case 3:case 4:case 5:
						texte[i]='A';
						break;
					case 6:case 7:case 8:case 9:case 10:case 11:
						texte[i]='a';
						break;
					case 12:case 13: case 14:case 15:case 16:case 17:
						texte[i]='O';
						break;
					case 18:case 19: case 20:case 21:case 22:case 23:
						texte[i]='o';
						break;
					case 24:case 25: case 26:case 27:
						texte[i]='E';
						break;
					case 28:case 29: case 30:case 31:
						texte[i]='e';
						break;
					case 32:
						texte[i]='C';
						break;
					case 33:
						texte[i]='C';
						break;
					case 34:case 35: case 36:case 37:
						texte[i]='I';
						break;
					case 38:case 39: case 40:case 41:
						texte[i]='i';
						break;
					case 42:case 43: case 44:case 45:
						texte[i]='U';
						break;
					case 46:case 47: case 48:case 49:
						texte[i]='u';
						break;
					case 50:
						texte[i]='y';
						break;
					case 51:
						texte[i]='N';
						break;
					case 52:
						texte[i]='n';
						break;
				}*/			
			
		}
	}
}