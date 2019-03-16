#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct Item{
	int stdno;
	char name;
	char surname;
	char adress;
	struct Item *next;
};

typedef struct Item node; //ilk d���m� tutacak.

void yazdir(node *pt){
	while(pt!= NULL){ //liste bo� olmad��� s�rece
		printf("\n%d", pt->stdno); //pl nin x de�erini yazd�rcam.
		pt = pt->next; //pl yi bir sonraki d���me yolluyorum. ki d�ng� devam edebilsin.
	}
}
void ekle(node *pt, int x){
	while(pt->next != NULL){
		pt=pt->next;
	}
	pt->next = (node *)malloc(sizeof(node));
	pt->next->stdno = x;
	pt->next->next = NULL;
}
node *SiraliEkle(node *pt, int x){
	
	if(pt==NULL) {                                //liste bo�sa s�k�nt� yok ekleyece�im item ilk eleman olur.
		pt=(node *)malloc(sizeof(node));
		pt->next = NULL;
		pt->stdno = x;
		return pt;
	    }
	if(pt->stdno > x){                            //dolu listeye ekleyece�im item �n x de�eri 
			node *pr=(node*)malloc(sizeof(node));   //listedeki itemin x de�erinden b�y�kse ba�a eklerim.
			pr->stdno = x;
			pr->next = pt;
			return pr;//art�k ilk item �m yeni pr.
	    } 
	if(pt->stdno == x){
		printf("Student number has taken.");
		exit(1);
	}

	node *ara = pt;                          
	while(ara->next != NULL && ara->next->stdno <= x){ //liste aras�na eleman ekleme �art�m.
		ara=ara->next;
	}
	
	node *pr=(node*)malloc(sizeof(node));
	pr->next = ara->next;
	ara->next = pr;
	pr->stdno=x;
	if(ara->stdno == pr->stdno){
		printf("Student number has taken.");
		exit(1);
	}
	return pt;	
}

int main() {
	int no;
	char name[200];
	char surname [200];
	char adress [200];
	node *rr;
	rr=NULL;
	
	do{
		printf("\nPLEASE");
		printf("\nenter the name: ");
		scanf("%s",&name);
		printf("enter the surname: ");
		scanf("%s",&surname);
		printf("enter the adress: ");
		scanf("%s",&adress);
		printf("enter the your student number:  ");
		scanf("%d",&no);
		rr=SiraliEkle(rr, no);
		yazdir(rr);
	}while(1);
	
	return 0;
}
