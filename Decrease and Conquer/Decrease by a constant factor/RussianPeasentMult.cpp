#include <iostream>

// Russian peasent multiplication uses bitwise operations but general strategy is decrease by a constant factor to design.
// It is very interesting way to multiply 2 numbers
// Time complexity is O(logn);

int russianPeasentMultiplication(int a, int b){
    int ans = 0; // Answer initialization

while(b > 0){ // Second number becomes 0
  if(b & 1){
     // when second number becomes odd, first number will be added to the answer
        ans += a;
    }
    a = a << 1; // Doubling the first number
    b = b >> 1; // halving the second number
} 
    return ans;
}
int main()
{
    int a,b;
    std:: cout << "Enter the first number: ";
    std::cin >> a; 
    std:: cout << "Enter the second number: ";
    std:: cin >> b;
    std::cout <<"Answer is: " <<  russianPeasentMultiplication(a, b) << std:: endl; 
}