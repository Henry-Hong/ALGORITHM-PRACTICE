#include <iostream>
using namespace std;
// Divde & Conquer

int arr[128][128], N, cntWhite=0, cntBlue=0;

int isPerfect(int sx, int sy, int ex, int ey){
    int std = arr[sy][sx];
    for(int i=sy; i<ey; i++){
        for(int j=sx; j<ex; j++){
            if(arr[i][j] != std) return 0;
        }
    }
    return 1;
}

void divideAndConquer(int size, int sx, int sy, int ex, int ey){
    if(size == 1 || isPerfect(sx, sy, ex, ey)){
        if(arr[sy][sx] == 0) cntWhite++;
        else cntBlue++;
        return;
    }

    divideAndConquer(size / 2, sx, sy, (sx+ex)/2, (sy+ey)/2);
    divideAndConquer(size / 2, (sx+ex)/2, sy, ex, (sy+ey)/2);
    divideAndConquer(size / 2, sx, (sy+ey)/2, (sx+ex)/2, ey);
    divideAndConquer(size / 2, (sx+ex)/2, (sy+ey)/2, ex, ey);
}

int main(){


    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    divideAndConquer(N, 0, 0, N, N);

    cout << cntWhite << "\n" << cntBlue;

    return 0;
}