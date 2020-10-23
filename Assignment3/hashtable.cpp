#include <iostream>
#include "array.cpp"
#include "linklist.cpp"

struct content{
    string word;
    int count = 1;
};

class Hashtable{
  public:
    //Array<LinkedList<content>> table;
    //Array<Array<content>> table;
    content ** table;
    Hashtable(int newSize){
        size = newSize;
        //table = Array<LinkedList<content>>(size);  //a size of 33 or up seg faults
        //table = Array<Array<content>>(size);      //a size of 65 or up seg faults
        table = new content*[0];
        for(int i=0;i<size;i++)
            table[i] = new content[size];
    }

    ~Hashtable(){
        delete table;
    }

    int hashStr(string str){
        int R = 31;
        int hash = 0;
        for(int i=0;i<str.length(); i++)
            hash = (R * hash + int(str[i])) % size;
        return hash;
    }

    void newElement(string element){
        int index = hashStr(element);
        cout << "hash: " << index << endl;
        //insert into hashtable; need to add chaining next
        table[index][0].word = element;//breaking here
    }

    int getSize(){
        return size;
    }

  private:
    int size = 100;
};