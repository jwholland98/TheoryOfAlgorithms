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
    hashtable.newElement(test2);//bs
    hashtable.newElement(test2);

    cin >> test3;
    hashtable.newElement(test3);//ey
    hashtable.newElement(test3);
    hashtable.newElement(test3);

    hashtable.newElement(test);
    
    hashtable.output();
    return 0;
}