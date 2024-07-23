#include <iostream>
using namespace std;

int merge(int [], int, int, int);
int mergeSort(int [], int, int);

int main()
{
    int arr1[] = {2, 4, 1, 3, 5};
    int arr2[] = {2, 3, 4, 5, 6};
    int arr3[] = {10, 10, 10};
    int inversionCount1 = mergeSort(arr1, 0, 4);
    int inversionCount2 = mergeSort(arr2, 0, 4);
    int inversionCount3 = mergeSort(arr3, 0, 2);
    cout << "<<<            Test Cases            >>>" << endl << endl;
    cout << "Input: N = 5, arr[] = {2, 4, 1, 3, 5}" << endl;
    cout << "Output: " << inversionCount1 << endl << endl;
    cout << "Input: N = 5, arr[] = {2, 3, 4, 5, 6}" << endl;
    cout << "Output: " << inversionCount2 << endl << endl;
    cout << "Input: N = 3, arr[] = {10, 10, 10}" << endl;
    cout << "Output: " << inversionCount3;

    return 0;
}

// Merges two subArrays of arr[].
// Left subArray is arr[leftIndex..middleIndex]
// Right subArray is arr[middleIndex+1..leftIndex]
int merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
    //indices
    int i, j, k;
    int inversionCount = 0;

    //size of left subArray usually greater than size of Right subArray
    int sizeOfLeftSubArray = middleIndex - leftIndex + 1; //size of left subArray
    int sizeOfRightSubArray = rightIndex - middleIndex;  //size of Left subArray

    // Create subArrays arrays
    int *leftSubArray = new int[sizeOfLeftSubArray];
    int *rightSubArray = new int[sizeOfRightSubArray];

    // Copy data to temp arrays leftSubArray[] and rightSubArray[]
    for (i = 0; i < sizeOfLeftSubArray; i++)
    {
        leftSubArray[i] = arr[leftIndex + i];
    }
    for (j = 0; j < sizeOfRightSubArray; j++)
    {
        rightSubArray[j] = arr[middleIndex + 1 + j];
    }


    //Comparing elements of both subArrays
    i = j = 0;
    k = leftIndex;

    while (i < sizeOfLeftSubArray && j < sizeOfRightSubArray)
    {
        if (leftSubArray[i] <= rightSubArray[j])
        {
            arr[k] = leftSubArray[i];
            i++;
        }
        else
        {
            arr[k] = rightSubArray[j];
            j++;
            inversionCount += (middleIndex - i + 1);
        }
        k++;
    }

    // Copy the remaining elements of left subArray (if there are any) to temp
    while (i < sizeOfLeftSubArray)
    {
        arr[k] = leftSubArray[i];
        i++;
        k++;
    }
    while (j < sizeOfRightSubArray)
    {
        arr[k] = rightSubArray[j];
        j++;
        k++;
    }
    delete[] leftSubArray;
    delete[] rightSubArray;

    return inversionCount;
}

int mergeSort(int arr[], int leftIndex, int rightIndex)
{
    // As long as we do not reach base case
    if (leftIndex < rightIndex)
    {
        // find middleIndex
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        int inversionCount = 0;

        // recursively divide arr into two subArrays until reach base case
        inversionCount += mergeSort(arr, leftIndex, middleIndex);
        inversionCount += mergeSort(arr, middleIndex+1, rightIndex);

        inversionCount += merge(arr, leftIndex, middleIndex, rightIndex);

        return inversionCount;
    }
    return 0;
}
