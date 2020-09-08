#include <iostream>
#include <stdlib.h>
#include <chrono>
#include "../array/IntIndColl.cpp"

using namespace std;
using namespace std::chrono; //code for chrono taken from https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

//Insertion Sort:
//A=array; n is size of array
template <class T>
void insertSort(IntIndColl<T> &A, int n){
    for (int i=1;i<=n-1;i++){           //iterates through each element in array
        T v = A[i];
        T j = i - 1;
        while (j>=0 && A[j]>v){         //checks for correct position and places it there
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

//merge arrays B and C into A; n is size of A
template <class T>
void merge(IntIndColl<T> &B, IntIndColl<T> &C, IntIndColl<T> &A, int n){
    T i = 0, j = 0, k = 0;            //iterators
    T p = (n/2);                      //size of B
    T q = n-(n/2);                    //size of C
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
template <class T>
void mergeSort(IntIndColl<T> &A, int n){
    if(n>1){
        IntIndColl<T> B(n/2);         //create array for first half if A
        IntIndColl<T> C(n-(n/2));     //create array for second half if A
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
    if (argc < 2){
        cerr << "Usage: ./imsort <size of array> <upper bound for int> <upper bound for long long int>" << endl;
        exit(0);
    }
    int size, ubound;
    long long int lliubound;
    srand(700445452);                           //set seed for rng
    size = atoi(argv[1]);                       //set size of array
    if (argc > 2){                              //set upper bound
        ubound = atoi(argv[2]);
        lliubound = strtoll((argv[3]), nullptr, 0);
    }
    else{
        ubound = 2147483647;
        lliubound = 9223372036854775807;
    }

    IntIndColl<int> arr(size);
    IntIndColl<long long int> lliarr(size);

    //need to make dynamic and remove size from above
    for (int i = 0; i < size; i++)              //input random number based on seed into the array
    {
        arr[i] = rand() % ubound;//add multiplcation by INT_MAX and RAND_MAX
        lliarr[i] = (rand()*4294967298) % lliubound;   //set upper limit of rand to long long int
        /*cout << "A[" << i << "] = " << arr[i] << endl;        //output numbers contained in array
        cout << "Along[" << i << "] = " << lliarr[i] << endl;*/
    }

    IntIndColl<int> arr2(size);       //create new array for second sort
    IntIndColl<long long int> lliarr2(size);
    arr2.Copy(arr);                             //copy into new array
    lliarr2.Copy(lliarr);

    cout << "Starting Insertion Sort" << endl;
    auto start = high_resolution_clock::now();
    insertSort(arr, size);                   //run insertion sort
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Insertion Sort Time: " << duration.count() << " microseconds" << endl << endl;

    cout << "Starting Merge Sort" << endl;
    start = high_resolution_clock::now();
    mergeSort(arr2, size);                   //run merge sort
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Merge Sort Time: " << duration.count() << " microseconds" << endl << endl;

    cout << "Starting Insertion Sort with long long ints" << endl;
    start = high_resolution_clock::now();
    insertSort(lliarr, size);                //run insertion sort
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Long Long Int Insertion Sort Time: " << duration.count() << " microseconds" << endl << endl;

    cout << "Starting Merge Sort with long long ints" << endl;
    start = high_resolution_clock::now();
    mergeSort(lliarr2, size);                //run merge sort
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Long Long Int Merge Sort Time: " << duration.count() << " microseconds" << endl << endl;

    //[DEBUGGING]
    cout << "Insertion Sort:" << endl;
    for (int i = 0; i < size; i++)            //output numbers to prove it is sorted
    {
        cout << arr[i] << endl;
    }
    cout << "Merge Sort:" << endl;
    for (int i = 0; i < size; i++)              //output numbers to prove it is sorted
    {
        cout << arr2[i] << endl;
    }
    cout << "Insertion Sort long:" << endl;
    for (int i = 0; i < size; i++)            //output numbers to prove it is sorted
    {
        cout << lliarr[i] << endl;
    }
    cout << "Merge Sort long:" << endl;
    for (int i = 0; i < size; i++)              //output numbers to prove it is sorted
    {
        cout << lliarr2[i] << endl;
    }
    return 0;
}