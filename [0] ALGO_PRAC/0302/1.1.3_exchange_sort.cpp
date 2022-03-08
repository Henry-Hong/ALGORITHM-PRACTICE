#include <iostream>
#include <vector>
using namespace std;

void exchange_sort(int n, vector<int>& S){
    for(int i = 1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if(S[i] > S[j]) 
                swap(S[i], S[j]);
        }
    }

    for(int i=1; i<=n; i++){
        cout << S[i] << " ";
    }

}

int main(){

    int n,x,location;
    cin >> n;

    vector<int> S(n+1);

    for(int i=1; i<=n ;i++){
        cin >> S[i];
    }

    exchange_sort(n, S);

    // for(int i=1; i<=n; i++){
    //     cout << S[i] << " ";
    // }

    return 0;
}