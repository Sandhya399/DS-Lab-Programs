#include <stdio.h>

// Function for Bubble Sort
void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function to combine two sorted parts
void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    // Compare elements and combine
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left part
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements from right part
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy combined array back
    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }
}

// Function for Merge Sort
void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        // DIVIDE
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // COMBINE
        merge(a, low, mid, high);
    }
}

// Function to display array
void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    int a[100];
    int n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n----- SORTING MENU -----\n");
        printf("1. Bubble Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                bubbleSort(a, n);

                printf("Array after Bubble Sort: ");
                display(a, n);
                break;

            case 2:
                mergeSort(a, 0, n - 1);

                printf("Array after Merge Sort: ");
                display(a, n);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}