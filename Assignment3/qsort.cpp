#include <iostream>
#include "array.cpp"

using namespace std;

void partition(Array<int*> &index, int left, int right, int &pivot){
    int lindex = left;
    int rindex = right+1;
    int pvalue = left;
    //cout << "got here 1" << endl;
    while(lindex < rindex){
        //cout << "got here 2" << endl;
        lindex++;
        while(*index[lindex] < *index[pvalue] && lindex < rindex-1){//seems to break here
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
            int* tmp = index[rindex];
            index[rindex] = index[lindex];
            index[lindex] = tmp;
        }
    }
    //cout << "got here 6" << endl;
    pivot = rindex;
    int* tmp = index[rindex];
    index[rindex] = index[left];
    index[left] = tmp;
}

void qsort(Array<int*> &index, int left, int right){
    int pivot;
    partition(index, left, right, pivot);
    if (pivot-1 > left)
        qsort(index, left, pivot-1);
    if (right > pivot+1)
        qsort(index, pivot+1, right);
}