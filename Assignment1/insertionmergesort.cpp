#include <iostream>
#include <stdlib.h>
#include "../array/IntIndColl.cpp"

using namespace std;

void insertSort(IntIndColl<int> &A, int n){
    for (int i=1;i<=n-1;i++){
        int v = A[i];
        int j = i - 1;
        while (j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

void merge(IntIndColl<int> &B, IntIndColl<int> &C, IntIndColl<int> &A, int n){
    int i = 0, j = 0, k = 0;
    int p = (n/2);
    int q = n-(n/2);
    while (i < p && j < q){
        if (B[i] <= C[j]){
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
        }
        k++;
    }
    if (i == p){
        for (int x=k;x<(p+q);x++)
            A[x] = C[j+x-k];
    }
    else{
        for (int x=k;x<(p+q);x++)
            A[x] = B[i+x-k];
    }
}

void mergeSort(IntIndColl<int> &A, int n){
    if(n>1){
        IntIndColl<int> B(n/2);
        IntIndColl<int> C(n-(n/2));
        for (int i=0;i<(n/2);i++)       //copy first half of A into B
            B[i] = A[i];
        for (int i=0;i<n-(n/2);i++)     //copy second half of A into C
            C[i] = A[(n/2)+i];
        mergeSort(B, (n/2));
        mergeSort(C, (n-(n/2)));
        merge(B, C, A, n);
    }
}

int main()
{
    int size, ubound;
    srand(700445452);                           //set seed for rng
    cout << "Size of array? ";
    cin >> size;                                //get size of array
    cout << "Upper bound? ";
    cin >> ubound;                              //set upper bound
    IntIndColl<int> arr(size);
    for (int i = 0; i < size; i++)              //input random number based on seed into the array
    {
        arr[i] = rand() % ubound;
        cout << "A[" << i << "] = " << arr[i] << endl;        //output numbers contained in array
    }
    cout << "--------------------------" << endl;
    IntIndColl<int> arr2(size);                 //create new array for second sort
    arr2.Copy(arr);                             //copy into new array
    insertSort(arr, size);                      //run insertion sort
    mergeSort(arr2, size);                      //run merge sort
    cout << "Insertion Sort" << endl;
    for (int i = 0; i < size; i++)              //output numbers to prove it is sorted
    {
        cout << arr[i] << endl;
    }
    cout << "Merge Sort:" << endl;
    for (int i = 0; i < size; i++)              //output numbers to prove it is sorted
    {
        cout << arr2[i] << endl;
    }
    return 0;
}