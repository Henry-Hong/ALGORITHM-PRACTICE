#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
vector<int> S;

void merge(int low, int mid, int high)
{
    cnt++;
    int i = low, j = mid + 1, k = 0;
    vector<int> U(high - low + 1);

    while (i <= mid && j <= high)
        U[k++] = (S[i] < S[j]) ? S[i++] : S[j++];
    if (i > mid)
        while (j <= high)
            U[k++] = S[j++];
    else
        while (i <= mid)
            U[k++] = S[i++];
    for (int t = low; t <= high; t++)
        S[t] = U[t - low];
}

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int t; cin >> t;
        S.push_back(t);
    }

    mergesort(0, n-1);

    cout << cnt << "\n";
    for(int i=0; i<n; i++){
        cout << S[i];
        if(i != n-1) cout << " ";
    }

    return 0;
}