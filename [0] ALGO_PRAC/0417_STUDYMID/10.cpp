#include <iostream>
using namespace std;

int collatz(int n){

  int cnt = 1;
  while(n != 1){
    if(n % 2 == 0) n /= 2;
    else n = n * 3 + 1;
    // cout << n << " ";
    cnt++;
  }
  // cout << "\n";
  return cnt;
}

int main(){

  int max = 0xffffffff;
  int maxIndex = -1;
  int min = 0x7fffffff;
  int minIndex = -1;

  int s, e;
  cin >> s >> e;

  for(int i=s; i<e; i++){
    int len = collatz(i);
    // cout << "i: " << i << " " << "len: " << len << "\n";
    if(len >= max){
      max = len;
      maxIndex = i;
    }
    if(len <= min){
      min = len;
      minIndex = i;
    }
  }
  
  cout << "minlen: " << min << " " << "maxlen: " << max << "\n";
  cout << "minValue: " << minIndex << " " << "maxValue: " << maxIndex << "\n";


  return 0;
}