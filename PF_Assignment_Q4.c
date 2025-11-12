#include<stdio.h>
int push(int stack[], int topofstack, int stacksize)
{
	if(topofstack<=stacksize-1)
	{
		topofstack++;
		printf("Enter integer to be added in the stack: ");
		scanf("%d", &stack[topofstack]);
		printf("Element added sucessfully!\n\n");
	}
	else
	{
		printf("The Stack is full!\n\n");
	}
	return topofstack;
}
int pop(int stack[], int topofstack)
{
	if(topofstack==-1)
	{
		printf("Stack is empty, Nothing popped!\n\n");
	}
	else
	{
		printf("The popped item is %d.\n\n", stack[topofstack]);
		topofstack--;
	}
	return topofstack;
}
void peek(int stack[], int topofstack)
{
	if(topofstack==-1)
		printf("The Stack is empty!\n\n");
	else
		printf("The topofstack element in stack is %d.\n\n", stack[topofstack]);
}
void display(int stack[], int topofstack)
{
	int i;
	if(topofstack==-1)
		{
			printf("The Stack is empty!\n\n");
			i++;
			return;
		}
	printf("%4s \t %7s\n", "S.No", "Element");
	for(i = 0; i<=topofstack; i++)
	{
		printf("%4d \t %7d\n", i+1, stack[i]);
	}
	printf("\n");
}
int main()
{
	int topofstack = -1;
	int stacksize = 5;
	int stack[stacksize];
	int num = 0;
	while(num!=5)
	{
		printf("Choose From Menu:\n1. Add Item in Stack\n2. Remove Item From Stack\n3. Last Element in Stack\n4. Display Stack\n5. Exit Program\nEnter Number: ");
		scanf("%d", &num);
		printf("\n");
		switch(num)
		{
			case 1:
				topofstack = push(stack, topofstack, stacksize);
				break;
			case 2:
				topofstack = pop(stack, topofstack);
				break;
			case 3:
				peek(stack, topofstack);
				break;
			case 4:
				display(stack, topofstack);
				break;
			case 5:
				printf("Program Exit!\n");
				break;
			default:
				printf("Invalid Input!\n");
				break;
		}
	}
	return 0;
}
