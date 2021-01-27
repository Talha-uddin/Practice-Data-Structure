#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 20

void enQueue(int);
void deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
    int choice,value;

    printf("****Queue Using Array****\n");
    while(1)
    {
        printf("\n1.Insertion\n2. Deletion\n3. Display\n4. Exit\n");
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

            default: printf("Wrong Seletion!!!Please try again....");

        }
    }
}

void enQueue(int value)
{
    if(rear == SIZE - 1){
        printf("\nQueue is Full!!!\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\nInsertion Successful!!!\n");
    }
}

void deQueue()
{
    if(front == rear){
        printf("Queue is Empty!!!\n");
    }
    else{
        printf("Deleted Element: %d",queue[front]);
        front++;
        if(front == rear){
            front = rear = -1;
        }
    }
}

void display()
{
    int i;
    if(front == rear){
        printf("Queue is Empty!!!\n");
    }
    else{
        printf("\nQueue element are: ");
        for(i=front; i<=rear; i++){
            printf("%d\t",queue[i]);
        }
    }
}