/*******************************************************************************************
 Filename: fib.cpp                                  
 Assignment No: 4                                     
 File Description: Implements Fibonnacci sequence in 3 different ways
                                                                  
 Date Last Modified: 11/14/2020

I declare that all material in this assessment task is my work except where there
is clear acknowledgement or reference to the work of others. I further declare that I
have complied and agreed to the CMU Academic Integrity Policy at the University
website.
http://www.coloradomesa.edu/student-services/documents
Submissions that do not include the above academic integrity statements will not be
considered.
Student Name: Jesse Holland UID: 700445452 Date: November 14, 2020
*******************************************************************************************/
#include <iostream> 

using namespace std;

//takes which Fibinacco number is wanted and returns that number
long long int fib(int n){
    if(n<=2)
        return 1;
    return fib(n-1) + fib(n-2);
}

//takes which Fibinacco number is wanted and a memoization array and returns that number
long long int fibTD(int n, long long int f[]){
    if(f[n] != -1)
        return f[n];
    f[n] = fibTD(n-1, f) + fibTD(n-2, f);
    return fibTD(n-1, f) + fibTD(n-2, f);
}

//takes which Fibinacco number is wanted and a memoization array and returns that number
long long int fibBU(int n, long long int f[]){
    for(int i=3;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}

int main(){
    int in, n;
    cout << "Enter the value for n" << endl;
    cin >> n;
    long long int* f = new long long int[n+1];
    for(int i=0;i<n+1;i++){
        if(i<=2)
            f[i]=1;
        else
            f[i] = -1;
    }
    while(in != 0){
        cout << "Which Fibonacci would you like to use?" << endl <<
                "1.) Recursive - No Dynamic Programming" << endl <<
                "2.) Dynamic Programming - Top Down" << endl <<
                "3.) Dynamic Programming - Bottom Up" << endl << 
                "4.) Change n" << endl <<
                "0.) Exit" << endl << endl;
        cin >> in;
        if(in == 1)
            cout << "f(n) = " << fib(n) << endl << endl;
        else if(in == 2)
            cout << "f(n) = " << fibTD(n, f) << endl << endl;
        else if(in == 3)
            cout << "f(n) = " << fibBU(n, f) << endl << endl;
        else if(in == 3){
            cout << "Enter the value for n" << endl;
            cin >> n;
        }
        else if(in == 0)
            break;
    }
    delete f;
    cout << "Goodbye!" << endl;
    return 0;
}