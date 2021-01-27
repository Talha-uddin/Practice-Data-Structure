#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 100

void enQueue(int);
int deQueueFront();
int deQueueRear();
void enQueueRear(int);
void enQueueFront(int);
void display();

int queue[SIZE];
int rear = 0, front = 0;

int main()
{
    char ch;
    int choice1,choice2,value;
    printf("\n****** Type of Double Ended Queue ******\n");
    do
    {
        printf("\n1.Input-restricted deque \n");
        printf("2.Output-restricted deque\n");
        printf("\nEnter your choice of queue type : ");
        scanf("%d",&choice1);
        switch(choice1)
        {
            case 1:
                printf("\nSelect the Operation\n");
                printf("1.Insert\n2.Delete from Rear\n3.Delete from Front\n4.Display");
                do
                {
                    printf("\nEnter your chocie for operation in c deque: ");
                    scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: enQueueRear(value);
                            break;
                    case 2: value = deQueueRear();
                                printf("\nThe value is deleted is %d",value);
                                display();
                                break;
                    case 3: value = deQueueFront();
                                printf("\nThe value is deleted is %d",value);
                                display();
                                break;
                    case 4: display();
                            break;
                    default: printf("Wrong Choice!!");
                }
                printf("\nDo you want to perfom another operation(Y/N): ");
                ch = getch();
                } while (ch == 'y' || ch == 'Y');
                getch();
                break;
                

            case 2: printf("\n---- Select the Operation ----\n");
                    printf("1. Insert at Rear\n2. Insert at Front\n3. Delete\n4. Display");
                    do
                    {
                        printf("\nEnter your choice for the operation: ");
                        scanf("%d",&choice2);
                        switch(choice2)
                        {
                            case 1: enQueueRear(value);
                                    display();
                                    break;
                            case 2: enQueueFront(value);
                                    display();
                                    break;
                            case 3: value = deQueueFront();
                                    printf("\nThe value deleted is %d",value);
                                    display();
                                    break;
                            case 4: display();
                                    break;
                            default: printf("Wrong choice!!");
                        }
                        printf("\nDo you want to perform another operation(Y/N): ");
                        ch = getch();
                    } while(ch == 'y' || ch == 'Y');
                    getch();
                    break;
                    
        }
        printf("\nDo you want to Continue(Y/N");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
}

void enQueueRear(int value)
{
    char ch;
    if(front == SIZE/2)
    {
        printf("\nQueue is Full!!!Insertion Not Possible!!!");
        return;
    }
    do
    {
        printf("\nEnter the value want to be inserted: ");
        scanf("%d",&value);
        queue[front] = value;
        front++;
        printf("\nDo you want to continue insertion Y/N");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');
    
}

void enQueueFront(int value)
{
    char ch;
    if(front == SIZE/2)
    {
        printf("\nQueue is Full!!!Insertion is not possible!!!");
        return;
    }
    do
    {
        printf("\nEnter the value to be inserted: ");
        scanf("%d",&value);
        rear--;
        queue[rear] = value;
        printf("do you Want to Continue Y/N");
        ch = getch();
    } while (ch == 'y' || ch == 'Y');   

}

int deQueueRear()
{
    int deleted;
    if(front == rear)
    {
        printf("\nQueue is Empty!!!Deletion not Possible!!!");
        return 0;
    }
    front--;
    deleted = queue[rear + 1];
    return deleted;

}

int deQueueFront()
{
    int deleted;
    if(front == rear){
        printf("/nQueue is Empty!!!Deletion not Possible!!!");
        return 0;
    }
    rear++;
    deleted = queue[rear - 1];
    return deleted;
}

void display()
{
    int i;
    if(front == rear){
        printf("\nQueue is Empty!!!");
    }
    else{
        printf("\nThe Queue Element are:");
        for(i=rear; i<front; i++)
        {
            printf("%d\t ",queue[i]);
        }
    }
}