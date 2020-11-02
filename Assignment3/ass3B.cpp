/*******************************************************************************************
 Filename: ass3B.cpp                                  
 Assignment No: 3                                       
 File Description: Completes the 3rd step for Assignment 3. Finds the kth pivot from an 
 array of random integers. Results and possible implementations were discussed with
 Matthew Behnke and Kimlong Seng.
                                                                  
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

using namespace std;

//returns kth pivot of an array
void kthValue(Array<int> &index, int n, int k){
    int i = 0;
    while(k != i){
        int mid = n / 2;
        n--;
        int tmp = index[n];
        index[n] = index[mid];
        index[mid] = tmp;
        n--;
        tmp = index[n];
        index[n] = index[0];
        index[0] = tmp;
        n--;
        i++;
    }
    int mid = n / 2;
    if(index[0]<index[mid] && index[0]>index[n] || index[0]>index[mid] && index[0]<index[n])
        cout << index[0] << endl;
    else if(index[mid]<index[0] && index[mid]>index[n] || index[mid]>index[0] && index[mid]<index[n])
        cout << index[mid] << endl;
    else
        cout << index[n] << endl;
}

int main(int argc, char **argv){
    if(argc != 3){
        cerr << "usage error: ./<exe> <array size> <kvalue>" << endl;
        return 0;
    }
    Array<int> nums(stoi(argv[1]));
    int n = stoi(argv[1])-1;
    int k = stoi(argv[2]);
    srand(time(NULL));
    for(int i=0;i<nums.getSize();i++){
        nums[i] = (rand() % 10000) + 1;
    }
    kthValue(nums, n, k);
    return 0;
}