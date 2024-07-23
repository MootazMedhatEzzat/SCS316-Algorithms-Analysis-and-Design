#include <limits.h>
//#include <stdio.h>
#include <iostream>

using namespace std;

// A utility function to find maximum of two integers
int Max(int a, int b) { return (a > b) ? a : b; }


/*************************************************************************************************************************/



// A utility function to find maximum of three integers
int Max(int a, int b, int c) { return Max(Max(a, b), c); }



/*************************************************************************************************************************/



void printArray(int A[], int s)
{
    for (auto i = 0; i < s; i++)
        //This is a flag from the lines (45) and (58), this if statement will ignore printing these values.
        if(A[i] != INT_MIN)
            cout << A[i] << " ";
    cout<<endl;
}



/*************************************************************************************************************************/



// Find the maximum possible sum in arr[] such that arr[m]
// is part of it
int LargestCrossingSum(int arr[], int left, int m, int right)
{
    int temp[right+1];


 // Include elements on left of mid.
 int sum = 0;
 int left_sum = INT_MIN;
 for (int i = m; i >= left; i--) {
  sum = sum + arr[i];
  if (sum > left_sum){
   left_sum = sum;
  }
  else if(sum<left_sum)
            arr[i] = INT_MIN; //this line does will flag the eliminated values to -infinity ..
                                //this flag will lead the print function to ignore these values making a clean output ..
 }

 // Include elements on right of mid
 sum = 0;
 int right_sum = INT_MIN;
 for (int i = m; i <= right; i++) {
  sum = sum + arr[i];
  if (sum > right_sum){
   right_sum = sum;
        }
        else if(sum<right_sum)
            arr[i] = INT_MIN; //this line does will flag the eliminated values to -infinity ..
                                //this flag will lead the print function to ignore these values making a clean output ..
 }

 // Return sum of elements on left and right of mid
 // returning only left_sum + right_sum will fail for
 // [-2, 1]
 return Max(left_sum + right_sum - arr[m], left_sum, right_sum);
}



/*************************************************************************************************************************/



// Returns sum of maximum sum subarray in arr[l..h]
int LargestSubArraySum(int arr[], int left, int right)
{
 //Invalid Range: low is greater than high
 if (left > right)
  return INT_MIN;
 // Base Case: Only one element
 if (left == right)
  return arr[left];

 // Find middle point
 int m = (left + right) / 2;

 /* Return maximum of following three possible cases
   a) Maximum subarray sum in left half
   b) Maximum subarray sum in right half
   c) Maximum subarray sum such that the subarraycrosses the midpoint
    */
 return Max(LargestSubArraySum(arr, left, m - 1),
   LargestSubArraySum(arr, m + 1, right),
   LargestCrossingSum(arr, left, m, right));
}





int main()
{
    int arr[] = { -1, 2, 3, -4, 5, 6, -7, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = LargestSubArraySum(arr, 0, n - 1);
    cout << "given array is: arr [ "<< n << " ] = { -1, 2, 3, -4, 5, 6, -7, -8}" << endl;
    cout << "Maximum contiguous sum is " << max_sum << " found at" << endl;
    cout << "the subArray : ";
    printArray(arr,n);
    return 0;
}
