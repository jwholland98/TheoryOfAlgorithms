#include <iostream>
#include "qsort.cpp"

using namespace std;

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