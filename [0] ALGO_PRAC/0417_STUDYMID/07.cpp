// https://johngrib.github.io/wiki/problem/two-eggs-100-floor/
// 100층 건물과 2개의 계란문제

#include <iostream>
#include <vector>
using namespace std;

int main(){

  int floor;
  cin >> floor;

  int ans = 1;

  int t;
  while(true){
    t = (ans * (ans+1)) / 2;
    if(t > floor) break;
    ans++;
  }

  cout << ans;

  return 0;
}