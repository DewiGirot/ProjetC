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
#define ALPHABET 26

void cesar(char texte[], int clef);


void main(){
    char texte[] = "DAIZ";
    cesar(texte, 2);
}
	
void cesar(char texte[], int clef) {

	char tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	clef = clef % 26;

	while(texte[i] != '\0'){
		int f = 0;
		
		printf("i avant %c\n", texte[i]);
		while(tab[f] != texte[i]){
			f++;
		}
		
		//if ( i + clef > ALPHABET ) {
			texte[i] = tab[(f + clef - ALPHABET)];
		 } else { 
		 	texte[i] = tab[(f + clef)];
		 }
			
		
		printf("Voici %c\n", texte[i]);
		i++;
	}	
	
}