#include <iostream>

// Insertion sort algorithm designed by using Decrease and Conquer approach
// Time complexity => O(n^2) where the worst-case input is an array of strictly decreasing values.
// Best case => O(n)the comparison A[j]>temp is executed only once on every iteration of the outer loop.

void insertionSort(int arr[], int size)
{
    //Iterate over elements and add to temp
    for(int i=1; i<size; i++){
        int temp = arr[i];
        // Second iterator
        int j = i-1;
        //Comparison
        while(j>=0 && arr[j] >= temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<< " ";
    }
}

int main(){
    int arr[] = {5, 1, 56, 78, 65, 32, 44, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    print(arr,size);

    return 0;
}