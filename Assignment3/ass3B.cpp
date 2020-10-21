#include <iostream>
#include "array.cpp"

using namespace std;

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