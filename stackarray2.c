#include<stdio.h>
#define max 50
int stack[max];
int top=-1;
void push()
{
	int value;
	if(top==max-1)
	{
		printf("Stack overflow\n");
	}
	else
	{
		printf("\n enter value to push: ");
		scanf("%d",&value);
		top++;
		stack[top]=value;
		printf("value pushed successfully\n");
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\n stack is empty");
	}
	else
	{
		printf("%d is poped",stack[top]);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		printf("\n stack is empty\n");
	}
	else
	{
		printf("%d is peek element of the stack",stack[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\n stack is empty");
	}
	else
	{
		printf("\n stack element are:");
		for(i=top;i>=0;i--)
		{
			printf("%d-",stack[i]);
		}
	}
}
int main()
{
	int i,choice,n;
	printf("\n enter no of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		push();
	}
	
	
    printf("\n--- Stack Menu ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
	       printf("3. peek\n");
        printf("4\n display");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
            	peek();
            	break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice! Please select between 1-4.\n");
        }
    

    return 0;
}
