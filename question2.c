#include <stdio.h>

void bubbleSort(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printData(int arr[], int size)
{
    printf("Data After Sorted: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}
int main()
{
    int size;
    // int arr[5] = {12, 1212, 122, 123, 1233};

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Size is equal to %d\n", size);

    int arr[size];

    if (size <= 0)
    {
        printf("Invalid size, Please Try again");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        // printf("%d", size - 1);
        printf("Enter Element at position %d : ", i);
        scanf("%d", &arr[i]);
    }
    bubbleSort(size, arr);

    printData(arr, size);

    return 0;
}