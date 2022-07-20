#include <iostream>
#include <cmath>
#include <utility>
// Find the max element in a given array by using divide-and-conquer paradigm

int max(int a, int b){
    return a > b ? a : b;
}

std::pair<int, int> findMax(int arr[], int low, int high){
    // BaseCase of recurrence
    if(high - low == 1) 
        return {arr[low], low};
    // Recursion step
    // Mid point used to divide a given array into 2 parts
    int midPoint = (low + high) / 2;
     
    return max(findMax(arr, midPoint, high), findMax(arr, low, midPoint));
}


int main()
{
    int arr[] = {1,2,9,5,6,7,8,1};
    int low = 0;
    int size = sizeof(arr) / sizeof(arr[0]);    
    auto ans = findMax(arr, low, size);
    std::cout << "Max element position is: " <<  ans.second;
}