/*******************************************************************************************
 Filename: array.cpp                                  
 Assignment No: 2                                                  
 File Description: Contains array header info                               
                                                                  
 Date Last Modified: 10/1/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 1, 2020
*******************************************************************************************/

#ifndef ARRAY_H_
#define ARRAY_H_

template <class T>
class Array
{
 public:
    // constructor - use default argument
    // so only one needed
    Array(int sz = 100);

    // destructor
    ~Array();

    // store in index position a value
    void Store(int,T);

    // retrieve from index position
    T Retrieve(int) const;

    // copy an array
    void Copy(const Array&);

    //overload []
    T& operator[](int index);

    Array(const Array& src);

    void insert();

  private:
    // pointer to the array itself
    T *collection;

    // total size of array
    int size;
};

#endif 