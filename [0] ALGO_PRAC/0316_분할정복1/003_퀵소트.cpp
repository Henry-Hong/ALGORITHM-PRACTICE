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

// how to set pivot point.
// ex) left, rigth 중 더 큰값을 pivot으로 하는 quickSort를 작성하시오.
int partition_left(int low, int high){
    int pivotV = S[low];
    int j = low;
    for(int i = low + 1; i <= high; i++)
        if(S[i] < pivotV) 
            swap(S[++j], S[i]);
    swap(S[j], S[low]);
    return j;
}

// 역방향
int partition_right(int low, int high){
    int pivotV = S[high];
    int j = low;
    for(int i=low; i<high; i++){
        if(S[i] > pivotV){
            swap(S[j++], S[i]);
        }
    }
    swap(S[j], S[high]);
    return j;
}

int partition_mid(int low, int high){

    int mid = low + (high - low) / 2;
    

}

void quickSort(int low, int high)
{
    int pivotpoint;
    if (low < high)
    {
        // partition(low, high, pivotpoint);
        // pivotpoint = partition_right(low, high);
        pivotpoint = partition_left(low,high);
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