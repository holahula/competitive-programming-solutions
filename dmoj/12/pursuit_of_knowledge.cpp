#include <bits/stdc++.h>

using namespace std;

int n, m, t, a, b, q;

vector <int> room[1005];
int path[1005][1005] = {9999};

queue<int>lol;

bfs(){
  for(int i = 1; i <= n; i++){
      lol.push_back(i);
      


  }

}

int main() {

  cin >> n >> m >> t;

  for(int i = 0; i < m; i++){
    cin >> a >> b;
    room[a].push_back(b);
  }

  bfs();

  cin >> q;



  for(int i = 0; i < q; i++){
    cin >> a >> b;
    cout << path[a][b] << endl;
  }


}
