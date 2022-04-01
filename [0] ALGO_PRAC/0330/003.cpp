#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vector1d;
typedef vector<vector1d> vector2d;

int h;

void printPath(vector2d& arr, vector2d& path, int y, int x){
  if(y == -1) return;

  if(path[y][x] == 0) printPath(arr, path, y-1, x);
  else printPath(arr, path, y-1, x-1);
  cout << arr[y][x];
  if(y != h-1) cout << " ";
}

int main(){

  cin >> h;

  vector2d path(h, vector1d(h,0));
  vector2d dp(h,vector1d(h,0));
  vector2d arr(h, vector1d(h,0));

  for(int i=0; i<h; i++)
    for(int j=0; j<=i; j++)
      cin >> arr[i][j];

  //dp 일차원 배열로 안되나? ㅠㅠ
  dp[0][0] = arr[0][0];
  for(int i=1; i<h; i++){
    for(int j=0; j<=i; j++){
      dp[i][j] = arr[i][j];
      if(j != 0 && dp[i][j] < dp[i][j] + dp[i-1][j-1]) {
        dp[i][j] += dp[i-1][j-1];
        path[i][j] = 1;
      }
      if(dp[i][j] <= arr[i][j] + dp[i-1][j]) {
        dp[i][j] = arr[i][j] + dp[i-1][j];
        path[i][j] = 0;
      }
    }
  }

  int max = -1;
  for(int i=0; i<h; i++)
    if(dp[h-1][i] >= dp[h-1][max])
      max = i;
  
  cout << dp[h-1][max] << "\n";

  printPath(arr, path, h-1, max);

  return 0;
}