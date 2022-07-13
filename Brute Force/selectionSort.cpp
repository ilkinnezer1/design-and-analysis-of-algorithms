#include <iostream>

//Selection sort algoritm design by using brute force approach
//Selection sort runs O(n^2)

// Swap function to exchange values in comparison
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int arr[], int size){
    for(int i = 0; i < size; i++){
         std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void selectionSort(int arr[], int size)
{   //i defines first step of iteration
    for(int i = 0; i < size - 1; ++i){
        //Minimum index defines the min_index in array
        int min_index = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] < arr[min_index])
                min_index =j;
        };
        swap(&arr[min_index], &arr[i]);
    }
}

int main(){
    int arr[] = {10, 450, 12, 20, 1,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);
    std::cout << "Sorted array: ";
    print(arr, size);
}