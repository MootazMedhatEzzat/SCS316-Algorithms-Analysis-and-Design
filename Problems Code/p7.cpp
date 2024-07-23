#include<iostream>
#include<algorithm>
#include<climits>
#include <map>

using namespace std;

int removeDuplicates(int [], int);
int partition(int [], int, int, int);
int findMedian(int [], int);
void swap(int, int);
int kthLargest(int [], int, int, int);

int main()
{
	int arr1[] = {14, 5, 6, 12, 14, 8, 10, 6, 25};
	int arr2[] = {18, 15, 3, 1, 2, 6, 2, 18, 16};
	int arr3[] = {12, 3, 5, 7, 4, 19, 26};
	int n1 = sizeof(arr1)/sizeof(arr1[0]), k1 = 3;
	int n2 = sizeof(arr2)/sizeof(arr2[0]), k2 = 5;
	int n3 = sizeof(arr3)/sizeof(arr3[0]), k3 = 2;
    n1 = removeDuplicates(arr1, n1);
    n2 = removeDuplicates(arr2, n2);
    n3 = removeDuplicates(arr3, n3);

    cout << "<<<            Test Cases            >>>" << endl << endl;
    cout << "Input:" << endl;
    cout << "K = " << k1 << endl;
    cout << "A[] = {14, 5, 6, 12, 14, 8, 10, 6, 25}" << endl;
    cout << "Output: Kth largest element = " << kthLargest(arr1, 0, n1-1, n1-k1+1) << endl << endl;
    cout << "Input:" << endl;
    cout << "K = " << k2 << endl;
    cout << "A[] = {18, 15, 3, 1, 2, 6, 2, 18, 16}" << endl;
    cout << "Output: Kth largest element = " << kthLargest(arr2, 0, n2-1, n2-k2+1) << endl << endl;
    cout << "Input:" << endl;
    cout << "K = " << k3 << endl;
    cout << "A[] = {12, 3, 5, 7, 4, 19, 26}" << endl;
    cout << "Output: Kth largest element = " << kthLargest(arr3, 0, n3-1, n3-k3+1) << endl << endl;
	return 0;
}

//Function to remove duplicated values in the given array in O(n) time complexity
int removeDuplicates(int arr[], int n)
{
    map<int, int>mp ;
    int newSize = 0;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            arr[newSize] = arr[i];
            mp[arr[i]]++;
            newSize++;
        }
    }
    return newSize;
}

int partition(int arr[], int l, int h, int x)
{
	// Search for x in arr[l..h] and move it to end
	int i;
	for (i = l; i < h; i++)
    {
        if (arr[i] == x)
		{
		    break;
		}
    }
	swap(arr[i], arr[h]);

	i = l;
	for (int j = l; j <= h - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[h]);
	return i;
}
int findMedian(int arr[], int n)
{
	sort(arr, arr+n); // Sort the array
	return arr[n/2]; // Return middle element
}
void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int kthLargest(int arr[], int l, int r, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1;

		int i, median[(n + 4)/ 5];
		for (i = 0; i < n/5; i++)
        {
            median[i] = findMedian(arr + l + i * 5, 5);
        }

		if (i * 5 < n)
		{
			median[i] = findMedian(arr + l + i * 5, n % 5);
			i++;
		}

		int medOfMed;
		if (i == 1)
		{
			medOfMed = median[i-1];
		}
		else
        {
            medOfMed = kthLargest(median, 0, i-1, i/2);
        }

		int pos = partition(arr, l, r, k);

		// If position is same as k
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1) // If position is more, recur for left
			return kthLargest(arr, l, pos-1, k);

		// Else recur for right subarray
		return kthLargest(arr, pos+1, r, k-pos+l-1);
	}

	// If k is more than number of elements in array
	return INT_MAX;
}


