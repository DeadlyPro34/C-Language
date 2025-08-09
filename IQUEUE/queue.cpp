#include<stdio.h>
#define size 100

int queue[size];
int front = -1, rear = -1;

void insert()
{
	int item;
	if(rear == size - 1)
	{
		printf("Queue overflow(FULL)\n");
	}
	else
	{
		if(front == -1) front=0;
		printf("Enter the element to insert: ");
		scanf("%d", &item);
		rear++;
		queue[rear] = item;
		printf("%d inserted into the queue\n",item);
	}
}

void Delete()
{
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow (EMPTY)\n");
	}
	else
	{
		printf("Deleted element: %d\n", queue[front]);
		front++;
		if(front>rear)
		{
			front = rear = -1;
		}
	}
}

void display()
{
	if(front == 1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue elements: ");
		for(int i=front; i<=rear; i++)
		{
			printf("%d",queue[i]);
		}
		printf("\n");
	}
}

int main()
{
	int choice;
	do
	{
		printf("\n--QUEUE MENU--\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
			insert();
			break;
			
			case 2: 
			Delete();
			break;
			
			case 3: 
			display();
			break;
			
			case 4: 
			printf("Exit");
			break;
			
			default:
				printf("Invalid choice! Please try again.\n");
		}
	}
	while(choice !=4);
}
