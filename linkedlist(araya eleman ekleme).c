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

typedef struct Item node; //ilk düðümü tutacak.

void yazdir(node *pt){
	while(pt!= NULL){ //liste boþ olmadýðý sürece
		printf("\n%d", pt->stdno); //pl nin x deðerini yazdýrcam.
		pt = pt->next; //pl yi bir sonraki düðüme yolluyorum. ki döngü devam edebilsin.
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
	
	if(pt==NULL) {                                //liste boþsa sýkýntý yok ekleyeceðim item ilk eleman olur.
		pt=(node *)malloc(sizeof(node));
		pt->next = NULL;
		pt->stdno = x;
		return pt;
	    }
	if(pt->stdno > x){                            //dolu listeye ekleyeceðim item ýn x deðeri 
			node *pr=(node*)malloc(sizeof(node));   //listedeki itemin x deðerinden büyükse baþa eklerim.
			pr->stdno = x;
			pr->next = pt;
			return pr;//artýk ilk item ým yeni pr.
	    } 
	if(pt->stdno == x){
		printf("Student number has taken.");
		exit(1);
	}

	node *ara = pt;                          
	while(ara->next != NULL && ara->next->stdno <= x){ //liste arasýna eleman ekleme þartým.
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
