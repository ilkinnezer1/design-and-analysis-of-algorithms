#include <iostream>

//Bubble sort algoritm design made by using brute force approach
//Time complexity => O(n^2)

// Swapping array's element 
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j< size - i - 1; j++){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void print(int arr[], int size){
    for(int i = 0; i < size; i++){
        std::cout<<arr[i]<< " ";
    }
}

int main()
{
    int arr[] = {7,4,7,8,9,2,1,0,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    print(arr, size);
}

