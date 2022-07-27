#include <iostream>
#include <algorithm>
// Median finding algorithm designed by using Divide-and-Conquer in a deterministic way

double medianFinding(int arr[], int size)
{
    double median; // Median value can be a decimal point
    // Using efficient sorting algorithm for performance purposes
    std::sort(arr, arr + size);
    // After sorting, find the median for odd sized array
    median = arr[(size / 2)];
    //finding median for the even sized array
    if (size % 2 == 0) median = (median + arr[size / 2 - 1]) / 2;

    return median;
};

int main()
{
    int arr[] = {5,3,5,6,7,3,4,321,312,4,214,324,32,534,5,435,435,34};
    int size = sizeof(arr) / sizeof(int);
    double ans = medianFinding(arr, size);
    std:: cout << "Median is: " << ans;

}