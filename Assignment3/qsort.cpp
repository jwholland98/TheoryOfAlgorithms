/*******************************************************************************************
 Filename: qsort.cpp                                  
 Assignment No: 3                                       
 File Description: Implementation of quick sort that sorts an index array. Results and possible
 implementations were discussed with Matthew Behnke and Kimlong Seng. Quick sort code is based on
 code given by Dr. Sherine Antoun during class.
                                                                  
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

//swaps the content in the array at the two specified indices
void swapem(Array<int*> &index, int &A, int &B){
    int* tmp = index[A];
    index[A] = index[B];
    index[B] = tmp;
}

//intelligently choose pivot point
void Sort3(Array<int*> &index, int &A, int &B, int &C){
    if(*index[A] > *index[B])
        swapem(index, A, B);
    if(*index[A] > *index[C])
        swapem(index, A, C);
    if(*index[B] > *index[C])
        swapem(index, B, C);
}

//sort array around pivot point. Based on code given by Dr. Sherine Antoun during class.
void partition(Array<int*> &index, int left, int right, int &pivot){
    int middle = (left+right)/2;
    Sort3(index, left, middle, right);
    int lindex = left;
    int rindex = right+1;
    int pvalue = left;
    while(lindex < rindex){
        lindex++;
        while(*index[lindex] < *index[pvalue]){
            lindex++;
        }
        rindex--;
        while(*index[pvalue] < *index[rindex]){
            rindex--;
        }
        if(lindex < rindex){
            swapem(index, rindex, lindex);
        }
    }
    pivot = rindex;
    swapem(index, rindex, left);
}

//implementation of qsort. Based on code given by Dr. Sherine Antoun during class.
void qsort(Array<int*> &index, int left, int right){
    int pivot;
    partition(index, left, right, pivot);
    if (pivot-1 > left)
        qsort(index, left, pivot-1);
    if (right > pivot+1)
        qsort(index, pivot+1, right);
}