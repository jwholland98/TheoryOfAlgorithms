#include <iostream>
#include "array.cpp"

using namespace std;

void swapem(Array<int*> &index, int &A, int &B){
    int* tmp = index[A];
    index[A] = index[B];
    index[B] = tmp;
}

void Sort3(Array<int*> &index, int &A, int &B, int &C){
    if(*index[A] > *index[B])
        swapem(index, A, B);
    if(*index[A] > *index[C])
        swapem(index, A, C);
    if(*index[B] > *index[C])
        swapem(index, B, C);
}

void partition(Array<int*> &index, int left, int right, int &pivot){
    int middle = (left+right)/2;
    Sort3(index, left, middle, right);
    int lindex = left;
    int rindex = right+1;
    int pvalue = left;
    //cout << "got here 1" << endl;
    while(lindex < rindex){
        //cout << "got here 2" << endl;
        lindex++;
        while(*index[lindex] < *index[pvalue]){
            //cout << "got here 3" << endl;
            lindex++;
        }
        rindex--;
        while(*index[pvalue] < *index[rindex]){
            //cout << "got here 4" << endl;
            rindex--;
        }
        if(lindex < rindex){
            //cout << "got here 5" << endl;
            swapem(index, rindex, lindex);
        }
    }
    //cout << "got here 6" << endl;
    pivot = rindex;
    swapem(index, rindex, left);
}

void qsort(Array<int*> &index, int left, int right){
    int pivot;
    partition(index, left, right, pivot);
    if (pivot-1 > left)
        qsort(index, left, pivot-1);
    if (right > pivot+1)
        qsort(index, pivot+1, right);
}