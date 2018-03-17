#include <bits/stdc++.h>

using namespace std;

int docking(set<int, greater <int>> &gates, int p){
  int count = 0;
  int port;
  bool flag = true;

  for(int i = 0; i < p && flag; i++){
    cin >> port;
    set<int>::iterator nxt = gates.lower_bound(port);
    if(nxt != gates.end()){
      gates.erase(nxt);
      count ++;
    } else {
      flag = false;
    }
  }
  return count;
}

int main() {
  int p, g, ans;

  set< int, greater <int> > gates;

  cin >> g >> p;

  for(int i = 1; i <= g; i++){
    gates.insert(i);
  }

  ans = docking(gates, p);

  cout << ans << endl;

  return 0;
  // find greatest gate # <= port #
}
