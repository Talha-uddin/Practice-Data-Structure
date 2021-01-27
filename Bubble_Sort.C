#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 20

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int array[],int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
    }

    printf("\nSorted array:");
    for(i=0; i<size; i++)
    {
        printf("%d  ",array[i]);
    }
}

int main()
{
    int array[SIZE];
    int size,i;
    printf("Enter the Size of the Sort: ");
    scanf("%d",&size);

    printf("Enter %d Element for Sort: ",size);
    for(i=0; i<size; i++){
        scanf("%d",&array[i]);
    }

    BubbleSort(array,size);
}

