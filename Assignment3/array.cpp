/*******************************************************************************************
 Filename: array.cpp                                  
 Assignment No: 2                                                  
 File Description: Contains array structure. Code based on reference given by
 Dr. Sherine M. Antoun during first week's course material
                                                                  
 Date Last Modified: 10/3/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 3, 2020
*******************************************************************************************/

#include "array.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
Array<T>::Array(int sz)
{
    size = sz;
    collection = new T[sz];
}

template <class T>
Array<T>::~Array()
{
    delete [] collection;
}

template <class T>
void Array<T>::Store(int index, T value)
{
    if ((index < 0) || (index > size-1))
    {
    cerr << "\nERROR: index out of range\n";
    exit(1);
    }
    collection[index] = value;
}

template <class T>
T Array<T>::Retrieve(int index) const
{
    if ((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";
        exit(1);
    }
    return collection[index];
} 

template <class T>
void Array<T>::Copy(const Array& source)
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
T& Array<T>::operator[](int index)
{
    if ((index < 0) || (index > size-1))
    {
        cerr << "\nERROR: index out of range\n";
        exit(1);
    }
return collection[index];
}

template <class T>
Array<T>::Array(const Array& src)
{
    size = src.size;
    collection = new T[size]; // new space
    for (int i=0;i<src.size;i++)
    collection[i] = src.collection[i];
}

template <class T>
int Array<T>::getSize(){
     return size;
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


/*int main()
{
    int isize, howmany, i, data;
    // specify size of array needed
    cout << "Size of array needed? ";
    cin >> isize;
    // declare it
    Array<int> intarr(isize); // a safe array

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
}*/