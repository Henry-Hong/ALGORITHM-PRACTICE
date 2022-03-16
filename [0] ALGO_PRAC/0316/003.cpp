#include <iostream>
#include <vector>
using namespace std;

int cnt = -1;
vector<int> S;

void partition(int low, int high, int &pivotpoint)
{
    cnt++;
    int pivotitem = S[low];
    int j = low;
    for (int i = low + 1; i <= high; i++)
        if (S[i] < pivotitem)
        {
            j++;
            swap(S[i], S[j]);
        }
    pivotpoint = j;
    swap(S[low], S[pivotpoint]);
}

void quickSort(int low, int high)
{
    int pivotpoint;
    if (low < high)
    {
        partition(low, high, pivotpoint);
        quickSort(low, pivotpoint - 1);
        quickSort(pivotpoint + 1, high);
    }
}

int main()
{
    int n; cin >> n;

    for(int i=0; i<n; i++){
        int t; cin >> t;
        S.push_back(t);
    }

    int t;
    partition(0, n-1, t);
    for(int i=0; i<n; i++){
        cout << S[i];
        if(i != n-1) cout << " ";
    }

    quickSort(0, n-1);
    cout << "\n" << cnt << "\n";
    for(int i=0; i<n; i++){
        cout << S[i];
        if(i != n-1) cout << " ";
    }
    
    return 0;
}