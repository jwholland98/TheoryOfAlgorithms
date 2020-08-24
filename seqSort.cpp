#include <iostream>
#include <fstream>

using namespace std;
const int ARRSIZE = 1000;

int search(int arr[], int num){
    for(int i=0; i<ARRSIZE; i++){
        if(arr[i] == num)
            return i;
    }
    return -1;
}

int main(){
    int arr[ARRSIZE];
    fstream ifile;
    ifile.open("nums.txt");
    int num;
    int i = 0;
    while(ifile >> num){
        arr[i]=num;
        i++;
    }
    if(search(arr, 28880)<0)
        cout << "num not found" << endl;
    else
        cout << "found" << endl;

}