#ifndef INTINDCOLL_H_
#define INTINDCOLL_H_

template <class T>
class IntIndColl
{
 public:
    // constructor - use default argument
    // so only one needed
    IntIndColl(long long int sz = 100);

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