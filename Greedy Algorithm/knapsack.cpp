#include <iostream>
#include <climits>

using namespace std;
// Knapsack algorithm design with recursion
int knapSack(int value[], int weight[], int size ,int capacity)
{
    if(capacity < 0) return INT_MIN;
    if(size < 0 || capacity==0) return 0; // Basecase

    int inside = value[size] + knapSack(value, weight, size-1, capacity-weight[size]);
    int external = knapSack(value, weight, size-1, capacity);
    
    return max(inside, external);
}


int main() {
   int value[] = { 30, 50, 20, 10, 70, 90 };
   int weight[] = { 1, 2, 3, 6, 7, 4 };
   int capacity = 7;
   int size = sizeof(value) / sizeof(value[0]);
   cout << "Knapsack value is " << knapSack(value, weight, size - 1, capacity);
   return 0;
}