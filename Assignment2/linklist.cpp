/*******************************************************************************************
 Filename: linklist.cpp                                  
 Assignment No: 2                                                  
 File Description: Contains Linked List Data Structure                                 
                                                                  
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

#include <iostream>
#include "linklist.h"

using namespace std;

int ListDataCmp(int data1, int data2)
{
    int result = 1;
    if (data1 < data2)
        result = -1;
    else if (data1 == data2)
        result = 0;
    return result;
}

template<class T>
LinkedList<T>::LinkedList()
{
    current = 0;
    head = new node;
    tail = new node;
    head->next=tail;
    tail->prev=head;
    head->prev=NULL;
    tail->next-NULL;
}

template<class T>
LinkedList<T>::~LinkedList()//deallocate list
{
    nodePtr curr, next;
    curr = head;
    next = head->next;
    while(next!=tail){
        delete curr;
        curr = next;
        next = next->next;
    }
    delete curr;
    delete next;
}

template<class T>
bool LinkedList<T>::IsEmpty()
{
    return(head->next==tail);
}

template<class T>
T LinkedList<T>::RemoveFromHead()
{
    //complete later
}

template<class T>
void LinkedList<T>::Insert(const T& newdata)
{
    nodePtr curr, prev, newnode;
    newnode = new node;
    newnode->data = newdata;
    curr = head->next;
    prev = head;
    while (curr!=tail && ListDataCmp(newdata.weight,curr->data.weight) > 0)
    {
        prev = curr;
        curr = curr->next;
    }
    newnode->next=curr;

    prev->next=newnode;
    newnode->prev=prev;
    curr->prev=newnode;
}

template<class T>
void LinkedList<T>::InsertBack(const T& newdata)
{
    nodePtr curr, prev, newnode;
    newnode = new node;
    newnode->data = newdata;
    curr = head->next;
    prev = head;
    while (curr!=tail)
    {
        prev = curr;
        curr = curr->next;
    }
    newnode->next=curr;

    prev->next=newnode;
    newnode->prev=prev;
    curr->prev=newnode;
}

template<class T>
void LinkedList<T>::InsertFront(const T& newdata)
{
    nodePtr curr, next, newnode;
    newnode = new node;
    newnode->data = newdata;
    curr = tail->prev;
    next = tail;
    while (curr!=head)
    {
        next = curr;
        curr = curr->prev;
    }
    newnode->prev=curr;

    next->prev=newnode;
    newnode->next=next;
    curr->next=newnode;
}

template<class T>
void LinkedList<T>::Delete(const T& deldata){
    nodePtr curr, prev;
    curr = head->next;
    prev = head;
    while (curr!=tail && ListDataCmp(deldata,curr->data) != 0)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr==tail)
    {
        cerr << "Deletion Data Not Found!" << endl;
        exit(1);
    }
    prev->next=curr->next;
    curr->next->prev=prev;
    delete curr;
}

template<class T>
void LinkedList<T>::SetIterator(bool front)
{
    if(front)
        current = head->next;
    else
        current = tail->prev;
} 

template<class T>
T LinkedList<T>::Next()
{
    T tmp = current->data;
    current = current->next;
    return tmp;
} 

template<class T>
T LinkedList<T>::Prev()
{
    T tmp = current->data;
    current = current->prev;
    return tmp;
} 

template<class T>
bool LinkedList<T>::More()
{
     return (current != 0);
} 