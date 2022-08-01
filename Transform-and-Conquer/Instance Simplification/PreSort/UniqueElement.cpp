#include <iostream>
#include <algorithm>

int compare(const void* x, const void* y)
{
	const int* tempX = (int*) x;
	const int* tempY = (int*) y;
	if (*tempX > *tempY)
		return 1;
	else if (*tempX < *tempY)
		return -1;

	return 0;
}

bool preSortUniqueElement(int arr[], int size){
    // Presorting
    qsort(arr, size, sizeof(int), compare); // runs O(nlogn)
    //Checking element uniqueness

    for(int i = 0; i < size; ++i)
        if(arr[i] == arr[i+1])
            return false;
    
    return true;
}

int main(){
    int arr[] = {1,2,5,4,6,9};
    int size = sizeof(arr) / sizeof(int);
    int ans = preSortUniqueElement(arr, size);

    if(ans == true)
        std::cout << "Array is unique!" << std::endl;
    else    
        std::cout << "Array is not unique!" <<std::endl;
}