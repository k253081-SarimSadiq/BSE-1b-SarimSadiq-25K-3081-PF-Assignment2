#include <stdio.h>
#include <string.h>

void customerinfo();
void display();
void purchase(int code);
void additem();
void bill();
void invoice();
int inventory[100][3];
int cart[100];
int i,j,temp,temp2,found,code,totalbill,discount,discounted;
char promocode[8],name[50],cnic[15];

int main() {
	for (i=0;i<100;i++){
		for (j=0;j<3;j++){
			inventory[i][j]=0;
		}
	}
	// Initializing a few values
	totalbill=0;
	discount=0;
	
	inventory[0][0] = 101;  // product code
	inventory[0][1] = 50;   // quantity
	inventory[0][2] = 100;  // price

	inventory[1][0] = 102;
	inventory[1][1] = 10;
	inventory[1][2] = 200;

	inventory[2][0] = 103;
	inventory[2][1] = 20;
	inventory[2][2] = 300;

	inventory[3][0] = 104;
	inventory[3][1] = 8;
	inventory[3][2] = 150;

	customerinfo();
	display();
	additem();
	printf("\nEnter promocode or enter none: ");
	scanf("%s",promocode);
	invoice();
		
	return 0;
}

void customerinfo(){
	printf("Welcome to the store.\nEnter your name: ");
	scanf(" %[^\n]",&name);
	printf("Enter your CNIC: ");
	scanf(" %[^\n]",&cnic);
	}
	
void display(){
	printf("\nProduct code\t|Quantity in stock\t|Price per product\n");
	printf("------------------------------------------------------------\n");
	for (i=0;i<100 && inventory[i][0]!=0;i++){
		printf("%d\t\t|%d\t\t\t|%d\n",inventory[i][0],inventory[i][1],inventory[i][2]);
	}
	
}

void purchase(int code){
	found=0;
	for (i=0;i<100 && found==0 && inventory[i][0]!=0;i++){
		if (code==inventory[i][0]){
			found=1;
			break;
		}
	}
	if (found==0){
		printf("\nProduct code not found\n");
	}
	else{
		printf("Enter quantity you want: ");
		scanf("%d",&temp2);	
		inventory[i][1]=inventory[i][1]-temp2;
		totalbill=totalbill+(inventory[i][2]*temp2);
	}
} 

void additem(){
	printf("\nEnter product code of the item you want to add into your cart or enter 0 to exit.\n");
	scanf("%d",&code);
		
		while(code!=0){
			purchase(code);
			printf("\nEnter product code of the item you want to add into your cart or enter 0 to exit.\n");
			scanf("%d",&code);
	}
}

void bill(){
	if (strcmp(promocode, "Eid2025") == 0){
		discount=25;
		discounted=totalbill*(1-(discount/100.0));
	}
	else{
		discounted=totalbill;
	}
	printf("\n_______________________________________\n");	
	printf("Your Bill before discount is Rs.%d\n",totalbill);
	printf("Applied Discount is %d%\n", discount);
	printf("Your Bill after discount is Rs.%d",discounted);
	printf("_______________________________________\n");
}

void invoice(){
	printf("\nThank you for shopping with us.\n");
	printf("Customer Name: %s\n",name);
	printf("Customer CNIC number: %s",cnic);
	bill();
}



