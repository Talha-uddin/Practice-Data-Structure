#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 20

void push(int);
void pop();
void display();

int stack[SIZE], top = -1;

int main()
{
    int choice,value;
    printf("****Stack Using Array****\n");
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
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

            default: printf("Wrong Selection!!!try again....\n");
        }
    }
}

void push(int value)
{
    if(top == SIZE - 1){
        printf("Stack is Full!!!");
    }
    else{
        top++;
        stack[top] = value;
        printf("\nInsertion Successful!!!\n");
    }
}

void pop()
{
    if(top == -1){
        printf("Stack is Empty!!!");
    }
    else{
        printf("\nDeleted Element: %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is Empty!!!");
    }
    else{
        int i;
        printf("Stack Element are: ");
        for(i=top; i>=0; i--){
            printf("%d  ",stack[i]);
        }
    }
}