#include <bits/stdc++.h>
using namespace std;



void multiply(int N, int** A, int **B, int **C)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    ///------------------------
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            cout << C[i][j]<<"\t";
        }
        cout<<endl;
    }
}



int main()
{
    int siz;
    cout<< "enter the array size: ";
    cin >> siz;
    int **arr1 = new int*[siz];
    int **arr2 = new int*[siz];
    int **arr3 = new int*[siz];

    for (int i = 0; i<siz; i++){
            arr1[i]=new int[siz];
            arr2[i]=new int[siz];
            arr3[i]=new int[siz];

    }


    for (int i=0;i<siz;i++)
    {
        for (int j=0;j<siz;j++)
        {
            cout << "enter the elemnts of array 1 : ";
            cin >> arr1[i][j];
        }
    }
    ///---------------------------
    for (int i=0;i<siz;i++)
    {
        for (int j=0;j<siz;j++)
        {
            cout << "enter the elemnts of array ( 2 ) : ";
            cin >> arr2[i][j];
        }
    }
    cout << "the multiplication of the tow arrays are : " << endl;
    multiply(siz,arr1,arr2,arr3);

    for (int i = 0; i<siz; i++){
        delete [] arr1[i];
        delete [] arr2[i];
        delete [] arr3[i];

    }
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;

    return 0;
}
