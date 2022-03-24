#include <iostream>
#include <vector>
using namespace std;

int order = 0;
typedef vector<vector<int> > vector2d;
typedef vector<int> vector1d;
typedef struct {int x; int y;} pos;
typedef vector<pos> vectorPos;

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
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << v[i][j];
            if(j == n-1) cout << "\n";
            else cout << " ";
        }
    }
}

void fillCenter(int n, int area, int sy, int sx, vector2d& V, vectorPos& fillPos){

    int m = n / 2;
    order += 1;
    if(area != 1){
        V[m-1][m-1] = order;
        fillPos[0].x = sx + m-1;
        fillPos[0].y = sy + m-1;
    }
    if(area != 2){
        V[m-1][m] = order;
        fillPos[1].x = sx + m;
        fillPos[1].y = sy + m-1;
    } 
    if(area != 3){
        V[m][m-1] = order;
        fillPos[2].x = sx + m-1;
        fillPos[2].y = sy + m;
    }
    if(area != 4){
        V[m][m] = order;
        fillPos[3].x = sx + m;
        fillPos[3].y = sy + m;
    }
}


void tromino(int n, int sy, int sx, int y, int x, vector2d& V){

    // n이 1이면 채울 필요도 없다.
    if(n == 1) return;

    // n이 2이면 채우기만하고 끝낸다. 나눌필요가없다.
    int area = getArea(n, sy, sx, y, x);    // 점이 어느 사분면에 있는지 알아낸다.
    pos p; p.x = x; p.y = y;
    vectorPos fillPos(4, p);
    fillCenter(n, area, sy, sx, V, fillPos);         //그 사분면을 제외한곳을 색칠한다.
    if(n == 2) return;

    // n이 4이상이면 4개로 나누어버린다.
    int m = n / 2;
    vector2d V11(m, vector1d(m,0));
    vector2d V12(m, vector1d(m,0));
    vector2d V21(m, vector1d(m,0));
    vector2d V22(m, vector1d(m,0));
    divide(n, V, V11, V12, V21, V22);

    // 각각에 대해 트로미노를 실시한다.
    // 색칠된 부분
    tromino(m, sy, sx, fillPos[0].y, fillPos[0].x, V11);
    tromino(m, sy, sx + m, fillPos[1].y, fillPos[1].x, V12);
    tromino(m, sy + m, sx, fillPos[2].y, fillPos[2].x, V21);
    tromino(m, sy + m, sx + m, fillPos[3].y, fillPos[3].x, V22);

    // 병합한다!
    combine(n, V, V11, V12, V21, V22);
}


int main(){

    int n, row, col;
    cin >> n >> row >> col;

    vector2d V(n, vector1d(n,0));

    tromino(n, 0, 0, row, col, V);

    print(n, V);

    return 0;
}