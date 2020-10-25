#include <iostream>
#include "array.cpp"
#include "linklist.cpp"

struct content{
    string word = "";
    int count = 1;
};

class Hashtable{
  public:
    //Array<LinkedList<content>> table;
    //Array<Array<content>> table;
    LinkedList<content> *table;

    Hashtable(int newSize){
        size = newSize;
        //table = Array<LinkedList<content>>(size);  //a size of 33 or up seg faults
        //table = Array<Array<content>>(size);      //a size of 65 or up seg faults

        table = new LinkedList<content>[size];
    }

    ~Hashtable(){
        //delete table;
    }

    int hashStr(string str){
        int R = 31;
        int hash = 0;
        for(int i=0;i<str.length(); i++)
            hash = (R * hash + int(str[i])) % size;
        return hash;
    }

    bool collision(int index){
        return !table[index].IsEmpty();
    }

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

    void newElement(string element){
        int index = hashStr(element);
        //cout << "hash: " << index << endl;
        if(!collision(index)){
            content tmp;
            tmp.word = element;
            table[index].InsertBack(tmp);
            wordCount++;
        }
        else
            chain(index, element);
    }

    int getSize(){
        return size;
    }

    int getWordCount(){
        return wordCount;
    }

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

  private:
    int size;
    int wordCount=0;
};

/*class Hashtable{
  public:
    //Array<LinkedList<content>> table;
    //Array<Array<content>> table;
    int *sizes;
    content ** table;

    Hashtable(int newSize){//note: table[0][0] is set to random characters and any attempt to change it breaks the program
        size = newSize;
        //table = Array<LinkedList<content>>(size);  //a size of 33 or up seg faults
        //table = Array<Array<content>>(size);      //a size of 65 or up seg faults

        sizes = new int[size];
        for(int i=0;i<size;i++)
            sizes[i] = 1;
        table = new content*[1];
        for(int i=0;i<size;i++){//breaking here
            cout << "got here " << i << endl;
            table[i] = new content[size];
        }
        //cout << "got here 4" << endl;
    }

~Hashtable(){
        delete table;
    }

    /*int hashStr(string str){
        int R = 31;
        int hash = 0;
        for(int i=0;i<str.length(); i++)
            hash = (R * hash + int(str[i])) % (size-1)+1;
        return hash;
    }

    void push(int index, string element){
        content *tmp = new content[sizes[index]+1];
        for(int i=0;i<sizes[index];i++)
            tmp[i] = table[index][i];
        table[index] = tmp;
        table[index][sizes[index]].word = element;
        sizes[index]++;
    }

    bool collision(int index){
        return (table[index][0].word != "");
    }

    void chain(int index, string element){
        for(int i=0;i<sizes[index];i++){
            if(table[index][i].word == element){
                table[index][i].count++;
                return;
            }
        }
        push(index, element);
    }

    void newElement(string element){
        int index = hashStr(element);
        //cout << "hash: " << index << endl;

        //insert into hashtable
        if(!collision(index))
            table[index][0].word = element;
        else
            chain(index, element);
    }

    int getSize(){
        return size;
    }

    void output(){
        int wordCount=0;
        for(int i=1;i<size;i++){
            //cout << "i: " << i << endl;
            for(int j=0;j<sizes[i];j++){
                //cout << "j: " << j << endl;
                if(table[i][j].word != ""){
                    cout << table[i][j].word << " :: count = " << table[i][j].count << endl;
                    wordCount++;
                }
            }
        }
        cout << "Total unique words: " << wordCount << endl;
    }

  private:
    int size = 100;
};*/