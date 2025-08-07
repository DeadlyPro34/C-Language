#include<stdio.h>
#include<conio.h>
#define size 5
	int stack[size], top = -1;
	void push(int v)
	{
		if (top == size-1)
			printf("overflow");
		else
			stack[top++] = v;	
	}
	void pop()
	{
		if(top == -1)
			printf("Underflow");
		else
		{
			printf("The popped element is %d\n",stack[top]);
			top --;
		}
	}
	void peep()
	{
		if (top == -1)
			printf("stack empty");
		else
			printf("The element of top is %d\n", stack[top]);
	}
	void change(int pos, int v)
	{
		if(pos<=0 || pos > top + 1)
			printf("Invalid position");
		else
		{
			stack[top - pos + 1] = v;
			if("Value %d is changed at position %d\n", v, pos);
		}
	}
	
	void display()
	{
		if (top == -1)
			printf("Stack is empty\n");
		else
		{
			printf("Stack elements: \n");
			for(int i=top;i>=0;i--)
				printf("%d\n",stack[i]);
		}
	}
	
	int main()
	{
		int choice, v , pos; 
		{
			printf("\n1.PUSH 2.POP 3.PEEP 4.CHANGE 5.DISPLAY 6.EXIT\n");
			printf("Enter Choice");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("Enter value of PUSH");
					scanf("%d",&v);
					push(v);
					break;
					
				case 2:
					pop();
					break;
				
				case 3:
					peep();
					break;
				
				case 4:
					printf("Enter the position to be change: ");
					scanf("%d",&pos);
					printf("Enter new value: ");
					scanf("%d",&v);
					change(pos, v);
					break;
					
				case 5:
					display();
					break;
					
				case 6:
					printf("EXIT");
					break;
					
				 default:
				 printf("Invalid choice");
			}
		}
		while(choice != 6);
	}
