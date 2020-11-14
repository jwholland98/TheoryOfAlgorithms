#include <iostream> 

using namespace std;

long long int fib(int n){
    if(n<=2)
        return 1;
    return fib(n-1) + fib(n-2);
}

long long int fibTD(int n, long long int f[]){
    if(f[n] != -1)
        return f[n];
    f[n] = fibTD(n-1, f) + fibTD(n-2, f);
    return fibTD(n-1, f) + fibTD(n-2, f);
}

long long int fibBU(int n, long long int f[]){
    for(int i=3;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}

//20: 12586269025 
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
                "0.) Exit" << endl << endl;
        cin >> in;
        if(in == 1)
            cout << "f(n) = " << fib(n) << endl << endl;
        else if(in == 2)
            cout << "f(n) = " << fibTD(n, f) << endl << endl;
        else if(in == 3)
            cout << "f(n) = " << fibBU(n, f) << endl << endl;
        else if(in == 0)
            break;
    }
    delete f;
    cout << "Goodbye!" << endl;
    return 0;
}