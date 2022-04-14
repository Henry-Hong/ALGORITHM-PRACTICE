#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
struct cmp {
	bool operator()(pii a, pii b) {
    if(a.second == b.second) return a.first > b.first; // > 오름차순, < 내림차순
    else return a.second > b.second;
	}
};
typedef priority_queue<pii, vector<pii>, cmp> PriorityQueue;

int main(){
  int n;
  cin >> n;

  int s, e;
  PriorityQueue pq;
  for (int i = 0; i < n; i++) {
    cin >> s >> e;
    pq.push(make_pair(s, e)); // pair.first: end, pair.second: start
  }

  int cnt = 1;
  e = pq.top().second; pq.pop();
  while (1) {
    if(pq.empty()) break;
    if (e <= pq.top().first) {
      e = pq.top().second;
      cnt++;
    }
    pq.pop();
  }

  cout << cnt;

  return 0;
}