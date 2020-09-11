/********************************************************************
* Filename: IntIndColl.h                                            *
* Assignment No: 1                                                  *
* File Description: Implements custom array                         *
*   based on code given by Sherrine Antoun                          *
*                                                                   *
* Date Last Modified: 9/11/2020                                     *
********************************************************************/

#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_

template <class T>
class IntIndColl
{
 public:
    // constructor - use default argument
    // so only one needed
    IntIndColl(T sz = 100);

    // destructor
    ~IntIndColl();

    // store in index position a value
    void Store(int,T);

    // retrieve from index position
    T Retrieve(int) const;

    // copy an array
    void Copy(const IntIndColl&);

    //overload []
    T& operator[](int index);

    IntIndColl(const IntIndColl& src);

    void insert();

  private:
    // pointer to the array itself
    T *collection;

    // total size of array
    int size;
};

#endif 