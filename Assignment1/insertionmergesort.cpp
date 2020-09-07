#include <iostream>
#include <stdlib.h>
#include "../array/IntIndColl.cpp"

using namespace std;

//Insertion Sort:
//A=array; n is size of array
void insertSort(IntIndColl<long long int> &A, int n){
    for (int i=1;i<=n-1;i++){           //iterates through each element in array
        int v = A[i];
        int j = i - 1;
        while (j>=0 && A[j]>v){         //checks for correct position and places it there
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

//merge arrays B and C into A; n is size of A
void merge(IntIndColl<long long int> &B, IntIndColl<long long int> &C, IntIndColl<long long int> &A, int n){
    int i = 0, j = 0, k = 0;            //iterators
    int p = (n/2);                      //size of B
    int q = n-(n/2);                    //size of C
    while (i < p && j < q){             //checks for smallest num until either iterator is equal to the arrays size
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
        for (int x=k;x<(p+q);x++)       //copy A[k..p+q-1] to C[j..q-1]
            A[x] = C[j+x-k];            //copies from j+iterator minus the offset of k
    }
    else{
        for (int x=k;x<(p+q);x++)       //copy A[k..p+q-1] to B[i..p-1]
            A[x] = B[i+x-k];            //copies from i+iterator minus the offset of k
    }
}

//Merge Sort:
//A=array; n is size of array
void mergeSort(IntIndColl<long long int> &A, int n){
    if(n>1){
        IntIndColl<long long int> B(n/2);         //create array for first half if A
        IntIndColl<long long int> C(n-(n/2));     //create array for second half if A
        for (int i=0;i<(n/2);i++)       //copy first half of A into B
            B[i] = A[i];
        for (int i=0;i<n-(n/2);i++)     //copy second half of A into C
            C[i] = A[(n/2)+i];
        mergeSort(B, (n/2));            //recursive call to further split up arrays
        mergeSort(C, (n-(n/2)));
        merge(B, C, A, n);              //merge arrays together after they have been separated out
    }
}

int main(int argc, char **argv)
{
    if (argc < 3){
        cerr << "Usage: ./imsort <size of array> <upper bound>" << endl;
        exit(0);
    }
    int size, ubound;
    srand(700445452);                           //set seed for rng
    size = int(strtol(argv[1], nullptr, 0));         //set size of array
    ubound = int(strtol(argv[2], nullptr, 0));       //set upper bound

    IntIndColl<long long int> arr(size);
    for (int i = 0; i < size; i++)              //input random number based on seed into the array
    {
        if (ubound > 2147483647)                    //set upper limit of rand to long long int if larger than int
            arr[i] = (rand()*4,294,967,298) % ubound;
        else
            arr[i] = rand() % ubound;
        cout << "A[" << i << "] = " << arr[i] << endl;        //output numbers contained in array
    }
    cout << "--------------------------" << endl;
    IntIndColl<long long int> arr2(size);                 //create new array for second sort
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