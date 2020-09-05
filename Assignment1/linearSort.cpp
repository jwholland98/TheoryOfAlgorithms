#include <iostream>
#include <stdlib.h>
#include "../array/IntIndColl.cpp"

using namespace std;
//Linear search:
//A=array; size is size of array; k is number being searched for
bool linSort(IntIndColl<int> A, int size, int k)
{
    int i = 0;
    bool found = false;
    while ((size-i-i)>0 && !found)
    { //loop until forward and backward search meet or number is found
        if (A.Retrieve(i) == k)                 //searches forward
            found = true;
        if (A.Retrieve(size-(i+1)) == k)        //searches backwards
            found = true;
        cout << "i: " << i << "  found: " << boolalpha << found << endl;
        i++;
    }
    return found;
}

int main()
{
    int size, ubound;
    srand(700445452);                           //set seed for rng
    cout << "Size of array needed? ";
    cin >> size;                                //get size of array
    cout << "Upper bound? ";
    cin >> ubound;                              //set upper bound
    IntIndColl<int> arr(size);
    for (int i = 0; i < size; i++)              //input random number based on seed into the array
    {
        arr.Store(i, rand() % ubound);
        cout << arr.Retrieve(i) << endl;        //output numbers contained in array
    }
    
    //output the result of the search; currently just searches for 1
    cout << boolalpha << linSort(arr, size, 1) << endl;
    return 0;
}