#include <iostream>

// Binary search is a remarkably efficient algorithm for searching in a sorted array.
// The standard way to analyze the efficiency of binary search is to count the number of times the search key is compared with an element of the array. 
// If we do mathematical analysis of recurrence then, Cworst(2k)=k+1=log2n+1. Generally, time complexity for avarage case will be approximately O(logn);


int binarySearchRecursive(int arr[], int low, int high, int target)
{
    // Calculate the middle point
    int midPoint = (low + high) / 2;
    // Basecase of recursion
    if(arr[midPoint] == target)
        return midPoint;
    // Recursive step
    if(arr[midPoint] > target)
    // Search on the left side
        return binarySearchRecursive(arr, low, midPoint - 1, target);
    else
    //Search on the rigth side
        return binarySearchRecursive(arr, midPoint + 1, high, target);    
}


int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int low = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = binarySearchRecursive(arr, low, size, 8);
    std::cout<<"Target is in index: " << ans << std::endl;
} 