/*
  • Time complexity for this problem will be O(N).

  • N -> Total Number Of policemen and thieves.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find maximum number of thieves caught.
int maxCaughtThieves(char [], int, int);

int main()
{
    int n, k;

    char arr1[] = {'P', 'T', 'T', 'P', 'T'};
    n = 5; k = 1;
    cout << "Input: " << endl;
    cout << "N = " << n << ", K = " << k << endl;
    cout << "arr[] = {P, T, T, P, T}" << endl;
    cout << "Output: " << maxCaughtThieves(arr1, n, k) << endl << endl;

    char arr2[] = {'T', 'T', 'P', 'P', 'T', 'P'};
    n = 6; k = 2;
    cout << "Input: " << endl;
    cout << "N = " << n << ", K = " << k << endl;
    cout << "arr[] = {T, T, P, P, T, P}" << endl;
    cout << "Output: " << maxCaughtThieves(arr2, n, k) << endl;

	return 0;
}

int maxCaughtThieves(char arr[], int arrSize, int k)
{
    vector<int> policemen; // To store positions of  policemen.
    vector<int> thieves;   // To store positions of  thieves.

    // Indices to keep track the current positions of thieves and policemen.
    int thi = 0, pol = 0;

    // To store the maximum number of thieves that the policemen can catch.
    int numOfCaughtThieves = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == 'P')
        {
            policemen.push_back(i);
        }
        else if (arr[i] == 'T')
        {
            thieves.push_back(i);
        }
    }

    // To determines the number of thieves that can be caught by policemen.
    while (pol < policemen.size() && thi < thieves.size())
    {
        // To check for the distance between each policeman and each thief.

        // If the distance between the policeman and thief less than or equal to k,
        // then this policeman can caught the thief.
        if (abs(thieves[thi] - policemen[pol]) <= k)
        {
            thi++;
            pol++;
            numOfCaughtThieves++;
        }
        // Else if the distance between the policeman and thief grater than k.
        else if (policemen[pol] < thieves[thi])
        {
            pol++;
        }
        else
        {
            thi++;
        }
  }
  return numOfCaughtThieves;
}
