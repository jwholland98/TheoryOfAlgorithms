#include <iostream>
#include "hashtable.cpp"

using namespace std;

int main(){
    string test;
    cin >> test;
    Hashtable hashtable(100);
    hashtable.newElement(test);
    cout << hashtable.table[hashtable.hashStr(test)][0].word << endl;
    return 0;
}