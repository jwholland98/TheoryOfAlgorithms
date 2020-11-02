/*******************************************************************************************
 Filename: ass3A.cpp                                  
 Assignment No: 3                                       
 File Description: Completes the 1st and 2nd steps for Assignment 3. Gets array of random
 integers and sends them to be sorted via quick sort and then outputted. Results and possible
 implementations were discussed with Matthew Behnke and Kimlong Seng.
                                                                  
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
#include "qsort.cpp"

using namespace std;

//outputs index array
void output(Array<int*> arr){
    int count = 0;
    for(int i=0;i<arr.getSize();i++){
        if(count>=10){
            count = 0;
            cout << endl;
        }
        cout << *arr[i] << "    ";
        count++;
    }
    cout << endl;
}

int main(int argc, char **argv){
    if(argc != 2){
        cerr << "usage error: ./<exe> <array size>" << endl;
        return 0;
    }
    Array<int> unsorted(stoi(argv[1]));
    Array<int*> sorted(stoi(argv[1]));
    srand(time(NULL));
    for(int i=0;i<unsorted.getSize();i++){
        unsorted[i] = (rand() % 10000) + 1;
        sorted[i] = &unsorted[i];
    }

    qsort(sorted, 0, sorted.getSize()-1);
    output(sorted);
    return 0;
}