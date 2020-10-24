#include <iostream>
#include "hashtable.cpp"

using namespace std;

int main(){
    //Hashtable hashtable(33);


    string test, test2, test3;
    cin >> test;
    Hashtable hashtable(100);
    hashtable.newElement(test);//test

    cin >> test2;
    hashtable.newElement(test2);//zt
    hashtable.newElement(test2);

    cin >> test3;
    hashtable.newElement(test3);//tf
    hashtable.newElement(test3);
    hashtable.newElement(test3);

    hashtable.newElement(test);

    cout << "word 1: " << hashtable.table[hashtable.hashStr(test)][0].word << endl;
    cout << "count 1: " << hashtable.table[hashtable.hashStr(test)][0].count << endl;

    cout << "word 2: " << hashtable.table[hashtable.hashStr(test2)][1].word << endl;
    cout << "count 2: " << hashtable.table[hashtable.hashStr(test2)][1].count << endl;

    cout << "word 3: " << hashtable.table[hashtable.hashStr(test3)][2].word << endl;
    cout << "count 3: " << hashtable.table[hashtable.hashStr(test3)][2].count << endl;
    return 0;
}