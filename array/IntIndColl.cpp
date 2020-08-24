#include "IntIndColl.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
IntIndColl<T>::IntIndColl(int sz)
// note no default argument value here
// has to be in one place or the other
{
    size = sz; // should check for +ve
    collection = new int[sz];
}

template <class T>
IntIndColl<T>::~IntIndColl()
{
    delete [] collection;
}

template <class T>
void IntIndColl<T>::Store(int index, T value)
{
    if ((index < 0) || (index > size-1))
    {
    cerr << "\nERROR: index out of range\n";
    exit(1);
    }
    collection[index] = value;
}

template <class T>
T IntIndColl<T>::Retrieve(int index) const
{
    if ((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";
        exit(1);
    }
    return collection[index];
} 

template <class T>
void IntIndColl<T>::Copy(const IntIndColl& source)
{
    if (source.size > size)
    {
        cerr << "\nERROR: coll. too large\n";
        exit(1);
    }
    for (int i=0;i<source.size;i++)
        collection[i] = source.collection[i];
}

template <class T>
int& IntIndColl<T>::operator[](int index)
{
    if ((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";
        exit(1);
    }
return collection[index];
}

template <class T>
IntIndColl<T>::IntIndColl(const IntIndColl& src)
{
    size = src.size;
    collection = new int[size]; // new space
    for (int i=0;i<src.size;i++)
    collection[i] = src.collection[i];
}

template <class T>
int ListDataCmp(const T& data1, const T& data2)
 {
    int result = 1;
    if (data1 < data2)
    result = -1;
    else if (data1 == data2)
    result = 0;
    return result;
 }


int main()
{
    int isize, howmany, i, data;
    // specify size of array needed
    cout << "Size of array needed? ";
    cin >> isize;
    // declare it
    IntIndColl<int> intarr(isize); // a safe array

    // fill a part of the array
    cout << "How much of array is occupied? ";
    cin >> howmany;
    for (i=0;i<howmany;i++)
    {
        cin >> data;
        intarr.Store(i,data);// use store function
    }
    // test the retrieve function
    cout << "Which item do you want? ";
    cin >> i;
    data = intarr.Retrieve(i);
    cout << "arr[" << i << "] = " << data << endl;
}