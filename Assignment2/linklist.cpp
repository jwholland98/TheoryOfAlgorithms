#include <iostream>
#include "linklist.h"

using namespace std;

int ListDataCmp(const int& data1, const int& data2)
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
LinkedList<T>::~LinkedList()
{
    //complete later if needed
}

template<class T>
void LinkedList<T>::AddToTail(const T& newdata)
{
    //complete later
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
    while (curr!=tail/* && ListDataCmp(newdata,curr->data) > 0*/)
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
bool LinkedList<T>::Locate(const T& locdata, T& NOTSURE)
{
    //complete later
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
void LinkedList<T>::SetIterator()
{
    current = head->next;
    //could maybe set next to NULL here
} 

template<class T>
T LinkedList<T>::Next()
{
    T tmp = current->data;
    current = current->next;
    return tmp;
} 

template<class T>
bool LinkedList<T>::More()
{
     return (current != 0);
} 

/*int main()
{
    LinkedList<int> list;
    int data;

    // set up the list
    list.Insert(1);
    list.Insert(2);
    list.Delete(2);

    list.SetIterator();
    while(list.More())
    {
        data = list.Next();
        // process data
        cout << data << endl;
    }
    return 0;
}*/