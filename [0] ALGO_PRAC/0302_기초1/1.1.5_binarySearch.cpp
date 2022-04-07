#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int>& arr, int num, int low, int high){
    if(low >= high) return -1;
    int mid = low + (high - low) / 2;
    if(num == arr[mid])
        return mid;
     else if(num < arr[mid])
        return binSearch(arr, num, low, mid-1);
     else if(num > arr[mid])
        return binSearch(arr, num, mid+1, high);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
        arr[i] = i;
    
    printf("num:");
    int num;
    cin >> num;

    cout << binSearch(arr, num, 0, n-1);

    return 0;
}