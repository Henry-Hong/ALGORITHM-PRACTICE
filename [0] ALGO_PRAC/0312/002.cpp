#include <iostream>
using namespace std;

int main()
{
    int n, k, m, arr[100][100], brr[100][100];

    cin >> n >> k >> m;


    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<k; i++){
        for(int j=0; j<m; j++){
            cin >> brr[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int sum=0;
            for(int t=0; t<k; t++)
                sum += (arr[i][t] * brr[t][j]);
            cout << sum;
            if(j != m-1)  cout << " ";
        }
        if(i != n-1) cout << "\n";
    }

}
