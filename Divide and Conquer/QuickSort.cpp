#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lomutoPartitioning(int arr[], int low, int high){
    // Pivot element declaration
    int pivotElement = arr[high]; //Usually in this partitioning pivot element can be the last element of a given array
    int smallerElementIndex = (low - 1);// Smaller element's index

    for(int j = low; j <= high-1; ++j)
    {
        if(arr[j] <= pivotElement){
            smallerElementIndex++;
            swap(&arr[smallerElementIndex], &arr[j]);
        }
    }
    swap(&arr[smallerElementIndex+1], &arr[high]);

    return (smallerElementIndex+1);
}


void quickSort(int arr[], int low, int high){
    if(low < high)
    {
        int partitionIndex = lomutoPartitioning(arr, low, high);
        //Pivot element and partitioning divides an array into 2 parts and make comparisons

        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high );
    }
}

void print(int arr[], int size)
{
    for(int i = 0; i < size; i++){
        std:: cout<< arr[i] << " ";
    }
}

int main()
{
    int arr[] = {4,8,2,4,6,8,9};
    int size = sizeof(arr)/ sizeof (int);
    quickSort(arr,0, size-1);
    std:: cout << "Sorted array: ";
    print(arr, size);
}

