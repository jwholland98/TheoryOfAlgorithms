#include <iostream>
#include "qsort.cpp"

using namespace std;

//[DEBUGGING]
void isSorted(Array<int*> index){
    for(int i=0;i< index.getSize()-1;i++){
        if(*index[i] > *index[i+1]){
            cout << "not sorted" << endl;
            return;
        }
    }
    cout << "sorted" << endl;
}

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
    if(argc < 2){
        cerr << "usage error" << endl;
        return 0;
    }
    Array<int> unsorted(stoi(argv[1]));
    Array<int*> sorted(stoi(argv[1]));
    srand(time(NULL));
    for(int i=0;i<unsorted.getSize();i++){
        unsorted[i] = rand() % 10000;
        sorted[i] = &unsorted[i];
    }

    qsort(sorted, 0, sorted.getSize()-1);
    output(sorted);
    //[DEBUGGING]
    /*cout << "Unsorted: " << endl;
    for(int i=0;i<unsorted.getSize();i++){
        cout << "   " << unsorted[i] << endl;
    }

    cout << "By index: " << endl;
    for(int i=0;i<sorted.getSize();i++){
        cout << "   " << *sorted[i] << endl;
    }*/
    isSorted(sorted);
    return 0;
}