#include "nekiHeader.h"
#include <stdlib.h>
#include <time.h>

int provera_f1(Cvor elem){
	

	if (elem.vlasnik!=0) return 0;

	if (elem.tip==1){
		if (elem.stepen_veze<3) return 0;
		else return 1;
	}else{
		if (elem.stepen_veze==1) return 1;
		else return 0;
	}
}

void oboj(Cvor *matrica, int n, int i, int j, int igrac){
		
	matrica[i*n+j].vlasnik=igrac;
	//

}

//srediti funkciju
void azuriranje_post_f1(Cvor *matrica, int n, int i, int j, int q, int igrac){
	int x,y,a,b;
	Cvor elem;

	switch(q){
		case 0:
			matrica[(i-1)*n+j].dole=NULL;
			matrica[(i-1)*n+j].stepen_veze--;
			
			if (matrica[(i-1)*n+j].tip!=0){
			
				if (matrica[(i-1)*n+j].stepen_veze==0){
					oboj(matrica,n,i-1,j,igrac);	
				}
			}

			matrica[i*n+j].gore=NULL;
			matrica[i*n+j].stepen_veze--;
			if (matrica[i*n+j].stepen_veze==0){
				oboj(matrica,n,i,j,igrac);	
			}
		case 1:
			matrica[i*n+j+1].levo=NULL;
			matrica[i*n+j+1].stepen_veze--;
			
			if (matrica[i*n+j+1].tip!=0){
			
				if (matrica[i*n+j+1].stepen_veze==0){
					oboj(matrica,n,i,j+1,igrac);	
				}
			}

			matrica[i*n+j].desno=NULL;
			matrica[i*n+j].stepen_veze--;
			if (matrica[i*n+j].stepen_veze==0){
				oboj(matrica,n,i,j,igrac);	
			}
		case 2:
			matrica[(i+1)*n+j].gore=NULL;
			matrica[(i+1)*n+j].stepen_veze--;
			
			if (matrica[(i+1)*n+j].tip!=0){
			
				if (matrica[(i+1)*n+j].stepen_veze==0){
					oboj(matrica,n,i+1,j,igrac);	
				}
			}
		case 3:
			matrica[i*n+j-1].desno=NULL;
			matrica[i*n+j-1].stepen_veze--;
			
			if (matrica[i*n+j-1].tip!=0){
			
				if (matrica[i*n+j-1].stepen_veze==0){
					oboj(matrica,n,i,j-1,igrac);	
				}
			}

			matrica[i*n+j].levo=NULL;
			matrica[i*n+j].stepen_veze--;
			if (matrica[i*n+j].stepen_veze==0){
				oboj(matrica,n,i,j,igrac);	
			}
			matrica[i*n+j].dole=NULL;
			matrica[i*n+j].stepen_veze--;
			if (matrica[i*n+j].stepen_veze==0){
				oboj(matrica,n,i,j,igrac);	
			}

	}
}

void zatvaranje_f1(skup_t *prvi_trojka, skup_t *djus){
	int p, fl=1,i;

	for (p=0; p<3 && fl; p++) {
		switch(p) {
			case 0:
				if (djus->element->gore!=NULL) {
					fl=0;
					djus->element->gore=NULL;
					}
				break;
			case 1:
				if (djus->element->desno!=NULL) {
					fl=0;
					djus->element->desno=NULL;
					}
				break;
			case 2:
				if (djus->element->dole!=NULL) {
					fl=0;					
					djus->element->dole=NULL;
					}
				break;
			case 3:
				if (djus->element->levo!=NULL) {
					fl=0;
					djus->element->levo=NULL;
					}
				break;
		}
	}

	prvi_trojka=brisanje
}
Cvor *potez_f1(Cvor *matrica, int m, int n, int igrac, skup_t *prvi_s){
	int i, j, fl=1, fl2=1,x,p,counter=0,m,q;
	Cvor *elem;
	skup_t *djus;
	
	//dali da generise po evidencionom nizu ili po matrici ili po SKUPU(po skupu)
	//potrebna jos jedna struktura $$
	
	srand(time(NULL));

	while (fl) {
		
		while (prvi_s!=NULL){
			m=rand()/(double)RAND_MAX*(m+n);
			djus=setanje(prvi_s,m);
			if (provera_f1(*(djus->element))){
				break;	
			}else{
				prvi_s=brisanje(prvi_s,djus);
			}
		}
		
		if (prvi_s==NULL) {
			break;
		}

		x=rand()/(double)RAND_MAX*3;

		for (p=0; p<3 && fl2; p++) {
		*q=(x+p)%4;
		switch(*q) {
			case 0:
				if (djus->element->gore!=NULL) {
					if (provera_f1(*(djus->element)->gore)) {
						fl=0;
						fl2=0;
						break;
					}
				}else break;
			case 1:
				if (djus->element->desno!=NULL) {
					if (provera_f1(*(djus->element)->desno)){
						fl=0;					
						fl2=0;
						break;
					}
				}else break;
			case 2:
				if (djus->element->dole!=NULL) {
					if (provera_f1(*(djus->element)->dole)) {
						fl=0;					
						fl2=0;
						break;
					}
				}else break;
			case 3:
				if (djus->element->levo!=NULL) {
					if (provera_f1(*(djus->element)->levo)){
						fl=0;
						fl2=0;
						break;
					}
				}else break;
		}
		}

		if (fl) {
			prvi_s=brisanje(prvi_s,djus);
		}
	}
	if (prvi_s!=NULL){
		azuriranje_post_f1(matrica, n, i, j, *q, igrac); //srediti ovu funkciju
		prvi_s=azuriranje_skupova(prvi_s, djus);
	}
	return &matrica[i*n+j];
}

int faza_1(Cvor *matrica, int m, int n,int *terminate, skup_t *prvi_s, skup_t *prvi_trojka){
	

	if (prvi_trojka!=NULL){

		
	}else{
		
	}
}



/*	generisanje druge faze se sastoji od razvajanja vise grafova koji su ,,iseceni"(stvoreni) u prvoj fazi , a zatim od odredjivanja ciklicnosti i stepenja grananja cvorova
	(znaci uzmes i samo razdvojis od jedne metrice napravis vise matrica susednosti, a zatim proveri sve ostalo kroz nju)
*/

