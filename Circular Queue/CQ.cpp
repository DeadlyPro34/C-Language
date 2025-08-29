#include<stdio.h>
#include<stdlib.h>
#define size 10

int queue[size];
int front=-1, rear=-1;

void insert(){
	int item;
	if((front==(rear + 1) % size)) 
	{
		printf("Queue overflow(full)\n");
	}
	else
	{
		printf("Enter the element to insert: ");
		scanf("%d",&item);
		
		if(front == -1)front=0;
		rear = (rear + 1)%size;
		queue[rear]=item;
		printf("%d Inserted into the queue\n",item);
	}
}

void dqueue(){
	if (front == -1) 
	{ 
        printf("Queue is empty!!\n");
    } 
	else {
        int element = queue[front];
        if (front == rear) 
		{ 
            front = rear = -1;
        } 
		else 
		{
            front = (front + 1) % size;
        }
        printf("Deleted element: %d\n", element);
    }
}

void display(){
	if(front == -1){
		printf("Circular queue is empty");
	}
	else{
		printf("Circular Queue elments: ");
		int i = front;
		while(1)
		{
			printf("%d",queue[i]);
			if(i==rear)
			break;
			i = (i + 1) % size;
		}
		printf("\n");
	}
}

int main(){
	int choice, value;
	while(1)
	{
		printf("\n...Circular Queue Menu...\n");
		printf("1.Insert\n 2.Delete\n 3.Display\n 4.Exit\n");
		printf("Enter choice:");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				dqueue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exit");
				return 0;
				default:
					printf("Invalid Choice!");
		}
	}
	while(choice!=4);
}
