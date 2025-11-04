#include <stdio.h>

void newbook();
void process();
void stockreport();
int isbns[100],quantities[100];
char titles[100][50];
float prices[100];
int i,user,isbn,isbnfound,sold;

int main() {
	for (i=0;i<=99;i++){
		isbns[i]=0;
	}
	do{
		printf("\nMain Menu:\nEnter 1 to add a new book.\nEnter 2 to process a sale.\nEnter 3 to generate low-stock report.\nEnter any other number to exit menu.\n");
		scanf("%d",&user);
		switch(user){
			case 1: newbook();
			break;
			case 2: process();
			break;
			case 3: stockreport();
			break;
			default: break;
	}
	}while(user>0 && user<4);
	
	return 0;
}

void newbook(){
	isbnfound=0;
	printf("Enter book isbns: ");
	scanf("%d",&isbn);
	for (i=0;isbnfound==0 && i<=99 && isbns[i]!=0;i++){
		if (isbns[i]==isbn){
			isbnfound=1;
		}
	}
	if (isbnfound==1){
		printf("\nIsbn: %d already present in record.",isbn);
	}
	else if(i==100){
		printf("\nStorage full.");
	}
	else {
		isbns[i]=isbn;
		printf("Enter book title: ");
		scanf(" %[^\n]",titles[i]);
		printf("Enter book price: ");
		scanf("%f",&prices[i]);			
		printf("Enter book quantity: ");
		scanf("%d\n",&quantities[i]);	
		}
	}
	
void process(){
	isbnfound=0;
	printf("Enter book ISBN: ");
	scanf("%d",&isbn);
	for (i=0;isbnfound==0 && i<=99 && isbns[i]!=0;i++){
		if (isbns[i]==isbn){
			isbnfound=1;
		}
	}
	if (isbnfound!=1){
		printf("\nIsbn: %d not found.",isbn);
	}
	else {
		printf("Enter book quanity sold: ");
		scanf("%d\n",&sold);
		quantities[i-1]=quantities[i-1]-sold;
	}
}

void stockreport(){
	printf("\nFollowing books have low stock-report:");
	for (i=0;i<=99 && isbns[i]!=0;i++){
		printf("\n");
		if (quantities[i]<5 && isbns[i]!=0){
			printf("Book isbn: %d\n",isbns[i]);
			printf("Book title: %s\n",titles[i]);		
			printf("Book price: %f\n",prices[i]);		
			printf("Book quanitity: %d\n",quantities[i]);		
		
	}
}
	
}
