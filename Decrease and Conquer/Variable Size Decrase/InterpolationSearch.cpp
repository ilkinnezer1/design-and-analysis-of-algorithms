#include <iostream>
#include <cmath>

int interpolationSearch(int arr[], int low, int high, int target)
{

    //BaseCase
    // Checking validity of a given array

    if(low <= high && arr[low] <= target && arr[high] >= target){

    // Initializing formula to calculate the current position
    int position = low + (((double)(high - low) / (arr[high] - arr[low]))) * (target - arr[low]); 

    //Checking validity of the position
    if(arr[position] == target)
        return position;
    else if(arr[position] > target)
    // Search on the left side
      return interpolationSearch(arr, low, position - 1, target); 
    else{
    // Searching in the right side
        return interpolationSearch(arr, position + 1, high, target);
    } 
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,7,9,10,12,15,17};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int target = 15;
    int ans = interpolationSearch(arr, 0, size - 1, target);

    if(ans == -1)
        std:: cout << "Not Found" << std:: endl;
    else   
        std:: cout << "Element is at index: " << ans << std:: endl;
}