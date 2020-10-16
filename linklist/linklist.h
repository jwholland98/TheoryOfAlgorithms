#ifndef LINKLIST_H_
#define LINKLIST_H_

template<class T>
int ListDataCmp(const T&, const T&);

template<class T> // or substituted type
class LinkedList
{
 public:
    // the following are as before
    LinkedList(); // constructor

    ~LinkedList(); // destructor

    void AddToTail(const T&);
    // previous store function

    bool IsEmpty();

    T RemoveFromHead();
    // previous retrieve function

    void Insert(const T&);
    bool Locate(const T&, T&);
    void Delete(const T&);
    // all using comparison

    void SetIterator();

    T Next();

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
    nodePtr head; //adding  "= NULL" fixes More()
    nodePtr tail;
    nodePtr current;
};
#endif