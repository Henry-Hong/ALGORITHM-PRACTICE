#include <iostream>
#define uint64 unsigned long long int 
using namespace std;

uint64 fib(int n, int max){

    if(n <= 1) return n;

    uint64 pp = 0, p = 1, result;
    for(int i = 0; i <= n-2; i++){
        result = (pp + p) % max;
        pp = p;
        p = result;
    }
    
    return result;
}

int main()
{

    int n, max;
    cin >> n >> max;

    cout << fib(n, max);

    return 0;
}