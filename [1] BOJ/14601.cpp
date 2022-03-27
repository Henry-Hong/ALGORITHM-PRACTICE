#include <iostream>
#include <vector>
using namespace std;

int order = 0;
typedef vector<vector<int> > vector2d;
typedef vector<int> vector1d;
typedef vector<pair<int,int> > vectorPos;

void divide(int n, vector2d& A, vector2d& A11, vector2d& A12, vector2d& A21, vector2d& A22){
    int m = n / 2;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+m];
            A21[i][j] = A[i+m][j];
            A22[i][j] = A[i+m][j+m];
        }
    }
}

void combine(int n, vector2d& A, vector2d& A11, vector2d& A12, vector2d& A21, vector2d& A22){
    int m = n / 2;
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            A[i][j] = A11[i][j];
            A[i][j+m] = A12[i][j];
            A[i+m][j] = A21[i][j];
            A[i+m][j+m] = A22[i][j];
        }
    }
}

int getArea(int n, int sy, int sx, int y, int x){
    int area = 1;
    int m = n / 2;
    if(x >= sx + m) area += 1;
    if(y >= sy + m) area += 2;
    return area;
}

void print(int n, vector2d& v){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cout << v[i][j];
            if(j == n-1) cout << "\n";
            else cout << " ";
        }
    }
}

vectorPos fillCenter(int n, int sy, int sx, int py, int px, vector2d& V){

    int area = getArea(n, sy, sx, py, px);    // 점이 어느 사분면에 있는지 알아낸다.

    order += 1;
    vectorPos pos(4, pair<int, int>(py,px));

    int m = n / 2;
    if(area != 1){
        V[m-1][m-1] = order;
        pos[0] = pair<int, int>(sy + m-1, sx + m-1);
    }
    if(area != 2){
        V[m-1][m] = order;
        pos[1] = pair<int, int>(sy + m-1, sx + m);
    } 
    if(area != 3){
        V[m][m-1] = order;
        pos[2] = pair<int, int>(sy + m, sx + m-1);
    }
    if(area != 4){
        V[m][m] = order;
        pos[3] = pair<int, int>(sy + m, sx + m);
    }
    return pos;
}


void tromino(int n, int sy, int sx, int py, int px, vector2d& V){

    if(n == 1) return;

    vectorPos pos = fillCenter(n, sy, sx, py, px, V);

    int m = n / 2;
    vector2d V11(m, vector1d(m,0)); vector2d V12(m, vector1d(m,0));
    vector2d V21(m, vector1d(m,0)); vector2d V22(m, vector1d(m,0));
    divide(n, V, V11, V12, V21, V22);

    tromino(m, sy, sx, pos[0].first, pos[0].second, V11);
    tromino(m, sy, sx+m, pos[1].first, pos[1].second, V12);
    tromino(m, sy+m, sx, pos[2].first, pos[2].second, V21);
    tromino(m, sy+m, sx+m, pos[3].first, pos[3].second, V22);

    combine(n, V, V11, V12, V21, V22);
}


int main(){

    int n, size = 1, row, col;
    cin >> n >> col >> row;

    for(int i=0; i<n; i++) size *= 2;
    row -= 1;
    col -= 1;

    vector2d V(size, vector1d(size,0));
    V[row][col] = -1;
    tromino(size, 0, 0, row, col, V);

    print(size, V);

    return 0;
}