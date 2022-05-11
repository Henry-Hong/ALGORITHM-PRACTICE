#include <iostream>
#include <vector>
using namespace std;

int V, E;
int cnt = 0;
vector<vector<int> > W;
vector<int> vindex;


bool promising(int i){
  bool flag = true;
  if(i == V-1 && !W[vindex[0]][vindex[V-1]]){ // 1. 회로조건
    flag = false;
  }
  else if(i > 0 && !W[vindex[i-1]][vindex[i]]){ // 2. 인접조건
    flag = false;
  }
  else{
    for(int j=1; j<i; j++){ // 3. 방문조건
      if(vindex[i] == vindex[j]){
        flag = false;
        break;
      }
    }
  }
  return flag;
}

void solve(int i){
  if(promising(i)){
    if(i == V-1){
      cnt++;
      // for(int k=1; k<V; k++){
      //   cout << vindex[k] << " ";
      // }
      // cout << "\n";
    }
    else {
      for(int j=2; j<=V; j++){
        vindex[i+1] = j;
        solve(i+1);
      }
    }
  }
}

int main(){

  int s, e;
  cin >> V >> E;

  vindex.resize(V+1, 1);
  W.resize(V+1, vector<int>(V+1, false));

  for(int i=0; i<E; i++){
    cin >> s >> e;
    W[s][e] = W[e][s] = true;
  }

  solve(0);

  cout << cnt;

  return 0;
}