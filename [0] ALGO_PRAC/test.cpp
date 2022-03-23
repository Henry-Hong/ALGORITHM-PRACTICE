#include <iostream>
#include <queue>
#include <string>
using namespace std;

void partition(int &a){
    a = 100;
}

void func2(int &a){
    a = 200;
}

int main() {
    int n;
    cin >> n;

    int a;
    cout << "a: " << a << "\n";
    partition(a);
    cout << "a: " << a << "\n";
    func2(a);
    cout << "a: " << a << "\n";

    return 0;
}