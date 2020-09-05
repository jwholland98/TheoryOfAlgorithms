#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv){
    srand(700445452);
    int amount, ubound;
    amount = strtol(argv[1], nullptr, 0);
    ubound = strtol(argv[2], nullptr, 0);
    ofstream ofile;
    ofile.open("nums.txt");
    for (int i=0;i<amount;i++)
    {
        ofile << rand()%ubound << ' ';
    }
    return 0;
}