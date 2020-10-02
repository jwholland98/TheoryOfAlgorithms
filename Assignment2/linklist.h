/*******************************************************************************************
 Filename: linklist.h                                  
 Assignment No: 2                                                  
 File Description: Contains Linked List Header info                                 
                                                                  
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

#ifndef LINKLIST_H_
#define LINKLIST_H_

template<class T>
int ListDataCmp(const T&, const T&);

template<class T> // or substituted type
class LinkedList
{
 public:
    LinkedList(); // constructor

    ~LinkedList(); // destructor

    bool IsEmpty();

    T RemoveFromHead();
    // previous retrieve function

    void Insert(const T&);
    void InsertBack(const T&);
    void InsertFront(const T&);
    bool Locate(const T&, T&);
    void Delete(const T&);
    // all using comparison

    void SetIterator(bool);

    T Next();
    T Prev();

    bool More();

    void InsertBeforeCurrent(const T&);
    
    T DeleteCurrent(); 

  private:
    struct node;
    typedef node *nodePtr;
    struct node
    {
        T data;
        nodePtr prev, next;
    };
    nodePtr head;
    nodePtr tail;
    nodePtr current;
};
#endif