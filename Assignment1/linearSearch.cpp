/********************************************************************
* Filename: linearSearch.cpp                                        *
* Assignment No: 1                                                  *
* File Description: Implements linear sort and double sided         *
*   linear sort                                                     *
*                                                                   *
* Date Last Modified: 9/11/2020                                     *
********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "IntIndColl.cpp"

using namespace std;

//Linear search:
//A=array; size = size of array; k = number being searched for
bool linSearch(IntIndColl<int> A, int size, int k)
{
    int i = 0;
    bool found = false;
    while (i < size && !found)
    { //loop until end of array or number is found
        if (A.Retrieve(i) == k)
            found = true;
        cout << "i: " << i << "  found: "
             << boolalpha << found << endl;
        i++;
    }
    return found;
}

//Two way Linear search:
//A=array; size is size of array; k is number being searched for
bool linSearch2(IntIndColl<int> A, int size, int k)
{
    int i = 0;
    bool found = false;
    //loop until forward and backward search meet or k is found
    while ((size - i - i) > 0 && !found)
    {
        if (A.Retrieve(i) == k) //searches forward
            found = true;
        if (A.Retrieve(size - (i + 1)) == k) //searches backwards
            found = true;
        cout << "i: " << i << "  found: "
             << boolalpha << found << endl;
        i++;
    }
    return found;
}

int main()
{
    int size, ubound;
    srand(700445452); //set seed for rng
    cout << "Size of array needed? ";
    cin >> size; //get size of array
    cout << "Upper bound? ";
    cin >> ubound; //set upper bound
    IntIndColl<int> arr(size);

    //input random number based on seed into the array
    for (int i = 0; i < size; i++)
    {
        arr.Store(i, rand() % ubound);
        cout << arr.Retrieve(i) << endl;
    }
    IntIndColl<int> arr2(size);
    arr2.Copy(arr); //copy into new array

    //output result of search; currently just searches for 1
    cout << boolalpha << linSearch(arr, size, 1) << endl;
    cout << boolalpha << linSearch(arr2, size, 1) << endl;
    return 0;
}