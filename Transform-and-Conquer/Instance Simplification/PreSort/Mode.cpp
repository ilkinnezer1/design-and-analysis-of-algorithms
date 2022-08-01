#include <iostream>
#include <algorithm>
#include <cmath>
// Mode is very useful in statistics and here I used transform-and-conquer paradigm to design the
// algorithm by using presort techique; 
// It defines an element that's most frequency in a given array;
// Time complexity is calculated by adding input size and max value in a given array
// As a result O(size + max) => with sorting it will be => O(nlogn) but for the worst case => O(n^2);

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
void findModeWithPresort(int arr[], int size)
{

// Presorting procedure with quicksort
    qsort(arr, size, sizeof(int), compare);

    // maximum element in the array
    int maxElement = *std::max_element(arr, arr + size);
    int temp = maxElement + 1;
    int modeFrequency[temp];

    for(int i = 0 ; i <  temp; ++i)
        modeFrequency[i] = 0;
    
    // Storing each input frequency
    for(int j = 0; j < size; ++j)
        modeFrequency[arr[j]]++;
    
    int mode = 0;
    int frequency = modeFrequency[0];
    for(int i = 1; i< temp; ++i){
        if(modeFrequency[i] > frequency) {
            frequency = modeFrequency[i];
            mode = i;
        }
    }
    std:: cout<< "mode is: " << mode;
}

int main(){
    int arr[] = {1,2,4,2,12,321,31,2321,3,12,3,2,1};
    int size = sizeof(arr) / sizeof(int);
    findModeWithPresort(arr, size);
}