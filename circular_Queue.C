/*Circular Queue Data Structure Using Array*/ 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
    int choice,value;

    printf("******Circular Queue using Array******\n");
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value you want to insert: ");
                    scanf("%d",&value);
                    enQueue(value);
                    break;
            case 2: deQueue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("Wrong Selection!!!Please try again..\n");
        }
    }
}

void enQueue(int value)
{
    if((rear == SIZE - 1 && front == 0) || (front == rear+1)){
        printf("Queue is Full!!!\n");
    }
    else{
        if(rear == SIZE -1 && front != 0){
            rear = -1;
        }
        queue[++rear] = value;
        printf("\nInsertion Successful!!!\n");
        if(front == -1){
            front = 0;
        }
    }
}

void deQueue()
{
    if(front == -1 && rear == -1){
        printf("List is empty!!!\n");
    }
    else{
        printf("\nDeleted element: %d",queue[front]);
        ++front;
        if(front == SIZE){
            front = 0;
        }
        if(front-1 == rear){
            front = rear = -1;
        }
    }
}

void display()
{
    if(front == -1){
        printf("List is Empty!!!\n");
    }
    else{
        int i = front;
        printf("\nCircular element are:\n");
        if(front <= rear){
            while(i <= rear)
                printf("%d\t",queue[i++]);
        }
        else{
            while(i <= SIZE - 1)
                printf("%d\t",queue[i++]);
            i = 0;
            while(i <= rear)
                printf("%d\t",queue[i++]);
        }

    }
}