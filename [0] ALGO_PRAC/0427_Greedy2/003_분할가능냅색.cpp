// page.75 참고하면 ez
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void selectionSort(int n, vector<int> &W, vector<int> &P){
  for(int i=2; i<=n; i++){
    for(int j=i; j>1; j--){
      int profitPerWeightR = P[j] / W[j];
      int profitPerWeightL = P[j-1] / W[j-1];
      if(profitPerWeightR > profitPerWeightL){
        swap(P[j], P[j-1]);
        swap(W[j], W[j-1]);
      }
    }
  }
}

void printItems(int totalProfit, vector<pair<int, int> > &items){
  cout << totalProfit << "\n";
  for(int j=0; j<items.size(); j++) 
    cout << items[j].first << " " << items[j].second << "\n";
}

void knapsack(int maxSize, vector<int> &W, vector<int> &P){

  int totalSize = 0;
  int totalProfit = 0;
  vector<pair<int, int> > items;

  for(int i=1; i<W.size() && totalSize != maxSize; i++){
    if(totalSize + W[i] <= maxSize){
      items.push_back(make_pair(W[i], P[i]));
      totalSize += items.back().first;
      totalProfit += items.back().second;
    }
    else{
      int capableSize = maxSize - totalSize;
      items.push_back(make_pair(capableSize, P[i] / W[i] * capableSize));
      totalSize += items.back().first;
      totalProfit += items.back().second; break;
    }
  }

  printItems(totalProfit, items);
}

int main(){

  int n;
  cin >> n;
  vector<int> W(n+1);     // Weight
  vector<int> P(n+1);     // Profit

  for(int i=1; i<=n; i++) cin >> W[i];
  for(int i=1; i<=n; i++) cin >> P[i];

  // selection sort, sort by profitPerWeight (descending order)
  selectionSort(n, W, P);

  // solve
  cin >> n;
  for(int i=0, maxSize; i<n; i++){
    cin >> maxSize;
    knapsack(maxSize, W, P);
  }

  return 0;
}
