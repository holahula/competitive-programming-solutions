#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<int>scale, int at, int q){
  for(int i = 1; i <= scale[at].size(); i++){
    if(scale[at][i] == q){
      return true;
    } else {
      bfs(scale, scale[at][i], q);
    }
  }
  return false;
}

int main() {

vector<vector<int>> taller (1000005); // x is taller than ...
vector<vector<int>> shorter (1000005); // y is shorter than ...
int n, m, p, q, x, y;

cin >> n >> m;

for(int i = 0; i < m; i++){
  cin >> x >> y; // x is taller than y
  shorter[x].push_back(y);
  taller[y].push_back(x);
}

cin >> p >> q;

if (bfs(taller, p, q)){
  cout << "yes" << endl;
} else if (bfs(shorter, p, q)){
  cout << "no" << endl;
} else {
  cout << "unknown" << endl;
}

  return 0;
}
