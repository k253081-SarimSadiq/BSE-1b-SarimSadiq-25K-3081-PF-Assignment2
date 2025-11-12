#include <stdio.h>

void Encoding(char str[])
{
	int i=0, len = 0, key=0;
	char reversestr[5000], encoded[5000];
	while(str[i] != '\n')
	{
		len ++;
		i ++;
	}
	for(i = 0; i < len; i++)
	{
		reversestr[i] = str[len-1-i];
		key = reversestr[i];
		encoded[i] = key ^ 18;
	}
	printf("\nThe encoded string is '%s'.\n\n", encoded);
	fflush(stdin);
}
void Decoding(char str[])
{
	int i=0, len = 0, key=0;
	char reversestr[5000], decoded[5000];
	while(str[i] != '\n')
	{
		len ++;
		i ++;
	}
	for(i = 0; i < len; i++)
	{
		key = str[len-1-i];
		decoded[i] = key ^ 18;
		reversestr[i] = decoded[i];
	}
	printf("\nThe decoded string is '%s'.\n\n", reversestr);
	fflush(stdin);
}
int main()
{
	char message[5000];
	int menuchoice=0;
	while(menuchoice != 3)
	{
		printf("Menu for Encoding and Decoding System!\n1. Encoding\n2. Decoding\n3. Exit\nEnter Number: ");
		scanf("%d", &menuchoice);
		switch(menuchoice)
		{
			case 1:
				printf("Enter message to be encoded: ");
				fflush(stdin);
				fgets(message, 5000, stdin);
				Encoding(message);
				break;
			case 2:
				printf("Enter message to be decoded: ");
				fflush(stdin);
				fgets(message, 5000, stdin);
				Decoding(message);
				break;
			case 3:
				printf("Program Exited!\n");
				break;
			default:
				printf("Invalid Input!\n");
				break;
		}
	}
	return 0;
}
