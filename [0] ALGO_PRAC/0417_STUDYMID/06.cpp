#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vec1d;
typedef vector<vec1d> vec2d;

int row, col;

void printArr(vec2d arr){
  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      cout << arr[i][j] << " "; 
    }
    cout << "\n";
  } 
}

void solve(int y, int x, vec2d &map, vec2d &path){

  if(y == row && x == col) return;

  int move = map[y][x];
  int dy = y + move;
  int dx = x + move;
  if(dy <= row){
    path[dy][x] = +move;
    solve(dy, x, map, path);
  }
  if(dx <= col){
    path[y][dx] = -move;
    solve(y, dx, map, path);
  }
}

void printPath(int y, int x, vec2d &path){

  if(path[row][col] == 0) return;
  if(y == 1 && x == 1){
    cout << "y: " << y << " " << "x: " << x << "\n";
    return;
  }

  int move = path[y][x];

  if(move < 0) { //
    printPath(y, x + move, path);
    cout << "y: " << y << " " << "x: " << x << "\n";
  }
  else{
    printPath(y - move, x, path);
    cout << "y: " << y << " " << "x: " << x << "\n";
  }

  
}

int main(){

  cin >> row >> col;

  vec2d map(row+1, vec1d(col+1, 0));
  vec2d path(row+1, vec1d(col+1, 0));

  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      cin >> map[i][j];
    }
  }

  solve(1, 1, map, path);

  printPath(row, col, path);

  printArr(path);

  if(path[row][col] != 0) cout << "쌉가능\n";
  else cout << "불가능\n";

  return 0;
}