#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}
// Lomuto partitoning assumes the pivot element as a last element of a given array
// Quicksort with lomuto partitioning is quite easy -> time complexity is O(n^2)
// It requires to  find an element that is not larger than one half of the list’s elements and not smaller than the other half. 
// This middle value is called the median, and it is one of the most important notions in mathematical statistics. 

int lomutoPartitioning(int arr[], int low, int high)
{
    // In Lomuto Partitioning the pivat element should be the last element given array
    int pivot = arr[high];
    int i = (low - 1); // Smaller element's index in given array

    for(int j = low; j <= high - 1; j++){
            if(arr[j] <= pivot){
                i++; // Increment index of smaller element
                swap(&arr[i], &arr[j]);
            } 
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
} 

void quickSortRecursive(int arr[], int low, int high)
{
    if(low < high){
        int partitioningIndex = lomutoPartitioning(arr, low ,high);

        //Seperation sorting => elements will be sorted before and after partitioning index
        quickSortRecursive(arr, low, partitioningIndex - 1);
        quickSortRecursive(arr, partitioningIndex + 1, high);
    };

}

void printResult(int arr[], int size)
{ 
    for(int i = 0; i < size; ++i )
    {
        std:: cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 2, 20, 1, 9, 0, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSortRecursive(arr, 0 , size - 1);
    std::cout << "Elements of sorted array: ";
    printResult(arr, size);
    
}