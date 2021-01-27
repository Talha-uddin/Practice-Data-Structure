#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

int main()
{
    int choice,value;

    printf("****Stack Using Linked List****\n");
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter the value you want to insert: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("Wrong input!!!try again...");
        }
    }
}

void push(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(top == NULL)
    {
        newNode->next = NULL;
    }
    else{
        newNode->next = top;
    }
    top = newNode;
    printf("Insertion Successful!!!\n");
}

void pop()
{
    if(top == NULL){
        printf("Stack is Empty!!!\n");
    }
    else{
        struct Node *temp = top;
        printf("\nDeleted Element: %d",temp->data);
        top = temp->next;
        free(temp);
    }
}

void display()
{
    if(top == NULL){
        printf("\nStack is Empty!!!\n");
    }
    else{
        struct Node *temp = top;
        while(temp->next != NULL){
            printf("%d--->",temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL",temp->data);
    }
}
