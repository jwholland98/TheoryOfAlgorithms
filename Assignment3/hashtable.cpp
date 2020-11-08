/*******************************************************************************************
 Filename: hashtable.cpp                                  
 Assignment No: 3                                       
 File Description: Contains the hashtable data structure. Currentl crafted to store words
 and their counts. Takes the size of the table as an argument. Results and possible
 implementations were discussed with Matthew Behnke and Kimlong Seng. The hash function is
 based on function used in:
 Algorithhms 4th Edition by Robert Sedgewick, Kevin Wayne
                                                                  
 Date Last Modified: 10/30/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: October 30, 2020
*******************************************************************************************/
#include <iostream>
#include "array.cpp"
#include "linklist.cpp"

//struct that stores each word and its count
struct content{
    string word = "";
    int count = 1;
};

//hashtable; creates a hash table using chaining; only argument is the size of the table(load factor)
class Hashtable{
  public:
    LinkedList<content> *table;

    //create table based on given size
    Hashtable(int newSize){
        size = newSize;
        table = new LinkedList<content>[size];
    }

    //deconstructor
    ~Hashtable(){
        
    }

    //hash function based on function implemented in:
    //Algorithhms 4th Edition by Robert Sedgewick, Kevin Wayne
    int hashStr(string str){
        int R = 31;
        int hash = 0;
        for(int i=0;i<str.length(); i++)
            hash = (R * hash + int(str[i])) % size;
        return hash;
    }

    //returns true if there is a collision
    bool collision(int index){
        return !table[index].IsEmpty();
    }

    //if a collision returns, chain the element
    void chain(int index, string element){
        table[index].SetIterator(true);
        for(int i=0;i<table[index].getSize();i++){
            content tmp = table[index].Next();
            if(tmp.word == element){
                table[index].updateCount();
                return;
            }
        }
        content tmp;
        tmp.word = element;
        table[index].InsertBack(tmp);
        wordCount++;
    }

    //add new element
    void newElement(string element){
        int index = hashStr(element);
        if(!collision(index)){
            content tmp;
            tmp.word = element;
            table[index].InsertBack(tmp);
            wordCount++;
        }
        else
            chain(index, element);
    }

    //returns size of hashtable
    int getSize(){
        return size;
    }

    //returns word count
    int getWordCount(){
        return wordCount;
    }

    //outputs all words and their counts
    void output(){
        for(int i=0;i<size;i++){
            if(!table[i].IsEmpty()){
                table[i].SetIterator(true);
                for(int j=0;j<table[i].getSize();j++){
                    content tmp = table[i].Next();
                    cout << tmp.word << " :: count = " << tmp.count << endl;
                }
            }
        }
        cout << "Total unique words: " << wordCount << endl;
    }

    //returns an array that contains all words and there counts
    content* getAllContent(){
        content* arr = new content[wordCount];
        int next = 0;
        for(int i=0;i<size;i++){
            if(!table[i].IsEmpty()){
                table[i].SetIterator(true);
                for(int j=0;j<table[i].getSize();j++){
                    content tmp = table[i].Next();
                    arr[next] = tmp;
                    next++;
                }
            }
        }
        return arr;
    }

    //display the count of a given word, or state that it doesn't appear in the text
    void showCount(string word){
        int index = hashStr(word);
        table[index].SetIterator(true);
        for(int i=0;i<table[index].getSize();i++){
            content tmp = table[index].Next();
            if(tmp.word == word){
                cout << "The count for " << word << " is: " << tmp.count << endl << endl;
                return;
            }
        }
        cout << '\"' << word << "\" does not appear in the text." << endl << endl;
    } 

  private:
    int size;
    int wordCount=0;
};