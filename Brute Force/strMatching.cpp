#include <iostream>
#include <cstring>
using namespace std;

// strlen(text) = n; strlen(pattern) = m
//Time complexity will be calculated for its comparisons
// comparisons will be (n-m+1) and complexity will be => O(nm);

void strMatching(char *text, char *pattern)
{
    //Checking all conditions
    if(strlen(text) < strlen(pattern))
        cout << "This is not valid" <<endl;
    if(strlen(text) == 0 && strlen(pattern) == 0)
        cout << "There is no comparison" << endl;
    if(strlen(text) == 0)
        cout << "Char can't be empty" << endl;

    // BruteForce string matching algorithm design
    for(int i = 0 ; i < strlen(text) - strlen(pattern); ++i)
    {
        int j = 0; // char iterator 

        while(text[i+j] == pattern[j] && j < strlen(pattern))
        {
            j++;
        }
        if(j == strlen(pattern))
            cout << "Pattern is at: " << i << endl;
    }
}

int main()
{
    char text[] = "AABACAADAABAAAABAABAA";
    char pattern[] = "AAB";
    strMatching(text, pattern);
    return 0;
}