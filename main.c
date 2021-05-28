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

int verificationCode (int clef);
int verificationChiffrage(int chiffrage);
int verificationCaracteresSpeciaux (char texte []);


void main () {

        char texte[50];
        int clef;
        int chiffrage;

        printf("Entrez votre message : \n");
        scanf("%s",&texte);

        printf("Entrez votre clef : \n");
        scanf("%d",&clef);
        
        
        while (verificationCode(clef) == -1) {
                printf("Erreur dans la saisie de la clef ! \n\n");
                printf("Entrez votre code et votre clef : \n");
                scanf("%d",&clef);
                printf("\n",clef);
        }

        printf("\n Voulez vous chifrer ou dechiffrer le message ? ( 1 pour Oui et -1 pour Non)\n ");
        scanf("%d",&chiffrage);

        while (verificationChiffrage(chiffrage) == -1) {
                printf("Erreur veuillez reessayer : ");
                scanf("%d",&chiffrage);
        }
        
        if(verificationChiffrage(chiffrage) == 1){
        	if (verificationCaracteresSpeciaux(texte) == 1) {
                printf("Votre texte possède des caractères spéciaux, ils ne changeront donc pas");
        	}  
        	      
        }

}

int verificationCode (int clef) {
        if (clef>26 || clef<1  ) {
                return -1 ;
        }
        return 1;
}

int verificationChiffrage (int chiffrage) {
        if (chiffrage>1 || chiffrage<-1  ) {
                return -1 ;
        }
        return 1;
}


int verificationCaracteresSpeciaux (char texte [] ) {
	//char caractereSpeciaux [] = {'&', 'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', 'Ç', 'È', 'É', 'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ò', 'Ó', 'Ô', 'Õ', 'Ù', 'Ú', 'Û', 'à', 'á', 'â', 'ã', 'ä', 'å', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ô', 'õ', 'ö', 'ù', 'ú', 'û', 'ü', 'ý'};
	
	//for(int i = 0, i<sizeof(texte), i++){
	//	int f = sizeof(caractereSpeciaux);
	//	for(int x = 0, x<f, x++){
	//		if(texte[i] == caractereSpeciaux[f]){
	//			printf("Erreur, vous avez un ou plusieurs caractère spécial"); 
	//		}
	//	}
	//}
}