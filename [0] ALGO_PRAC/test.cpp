#include <iostream>
#include <queue>
#include <string>
using namespace std;


int main() {

  string a;
  cin >> a;

  cout << a << "\n";

  a.insert(0, "a");
  cout << a;

  return 0;
}