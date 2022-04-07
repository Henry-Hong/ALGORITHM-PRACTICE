#include <iostream>
#include <vector>
using namespace std;

int cnt=0;

int binsearch(int n, vector<int> &S)
{
    int low, high, mid, pos=-1;
    low = 0;
    high = n-1;
    while (low <= high && pos == -1)
    {
        cnt++;
        mid = (low + high) / 2;
        if (mid == S[mid])
            return pos = mid;
        else if (mid < S[mid])
            high = mid - 1;
        else // mid > S[mid]
            low = mid + 1;
    }
    return pos;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    int ans = binsearch(n, v);
    cout << ans << "\n" << cnt;
}   
