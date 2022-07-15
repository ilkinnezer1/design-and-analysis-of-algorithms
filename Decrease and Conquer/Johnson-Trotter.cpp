#include <iostream>



int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool TO_RIGHT = true;
bool TO_LEFT = false;
// Finding the largest mobile integer in a given array
// mobile in such an arrow-marked permutation if its arrow points to a smaller number adjacent to it. 

int searchGreatestMobile(int arr[], int size, int mobileElement)
{
    for(int i = 0;i < size; ++i)
        if(arr[i] == mobileElement)
            return i + 1; // Pass the next mobile element to find the largest one
}

int findMobile(int arr[], bool direction[], int size)
{
    int prevMobile = 0, currMobile = 0;

    for(int i = 0; i<size; i++){
        if(direction[arr[i] - 1] == TO_LEFT && i!=0) // direction 0 means to left
            if(arr[i-1] < arr[i] && arr[i] > prevMobile)
                currMobile = arr[i];
                prevMobile = currMobile;
        
         // direction 1 means to right
        if(direction[arr[i] - 1] == TO_RIGHT && i != 0)
            if(arr[i] > arr[i+1] &&  arr[i] > prevMobile)
                currMobile = arr[i];
                prevMobile = currMobile;
    }

    // Utility function condition checking
    if(prevMobile == 0 && currMobile ==0)
        return 0;
    else    
        return currMobile;
}

int printSinglePermutation(int arr[], int size, bool direction[])
{
    int currMobile = findMobile(arr, direction, size);
    int greatestMobilePosition = searchGreatestMobile(arr, size, currMobile);

    //Swapping elements for their direction
        if(direction[arr[greatestMobilePosition - 1] - 1] == TO_LEFT)
            swap(&arr[greatestMobilePosition - 1], &arr[greatestMobilePosition - 2]);
        else if(direction[arr[greatestMobilePosition - 1] - 1] == TO_RIGHT)
            swap(&arr[greatestMobilePosition], &arr[greatestMobilePosition - 1]);

    //Direction changing for their values

    for(int i = 0; i < size; ++i){
        if(arr[i] > currMobile){
            if(direction[arr[i] - 1] == TO_RIGHT){
                direction[arr[i] - 1] = TO_LEFT;
            }else if(direction[arr[i] - 1] == TO_LEFT)
                direction[arr[i] - 1] = TO_RIGHT;  
        }   
    }
    for(int i = 0 ; i< size; ++i)
         std::cout<< "Elements: " <<  arr[i] << " ";       
}

int calculateFactorial(int size)
{   
    int ans  = 1;
    for(int i = 0; i < size; ++i){
        ans *= i;
    }
    return ans;
}

void printResult(int size)
{
    // Current permutation and direction storage
    int arr[size];
    bool direction[size];

    for(int i = 0 ; i < size; ++i){
        arr[i] = i + 1;
        std::cout << arr[i];
        std::cout << std::endl;
    }

    

    // In the first initialization all numbers are set to TO_LEFT for increasing order
         for(int i = 0 ; i < size; ++i)
            direction[i] = TO_LEFT;
        
    for(int i = 0 ; i < calculateFactorial(size); ++i)
        printSinglePermutation(arr, size, direction);

}

int main()
{
    int size = 4;
    printResult(4);
}