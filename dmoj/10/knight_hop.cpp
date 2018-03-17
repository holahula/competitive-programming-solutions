#include <bits/stdc++.h>
#define make_pair mp;
using namespace std;

typedef pair <int, int> pi;

int main() {
  vector<pi> m;
  bool flag = true;
  pi m1, m2, m3, m4, m5, m6, m7, m8, p1, p2;

  pi pm[10];
  int x1, y1, x2, y2;
  int ans = 0;

  cin >> x1 >> y1 >> x2 >> y2;


  p1 = pi(x1, y1);
  p2 = pi(x2, y2);

  m.push_back(p1);
  while(flag){
    ans++;
    int size = (int)m.size();
    for(int i = 0; i < size; i++){
      pm[0] = pi(m[i].first+1, m[i].second+2);
      pm[1] = pi(m[i].first+2, m[i].second+1);
      pm[2] = pi(m[i].first+2, m[i].second-1);
      pm[3] = pi(m[i].first+1, m[i].second-2);
      pm[4] = pi(m[i].first-1, m[i].second+2);
      pm[5] = pi(m[i].first-2, m[i].second+1);
      pm[6] = pi(m[i].first-2, m[i].second-1);
      pm[7] = pi(m[i].first-1, m[i].second-2);

      for(int j = 0; j < 8; j++){
        if(pm[j].first >=0 && pm[j].first <= 7 && pm[j].second >= 0 && pm[j].second <= 7){ // valid
          if(pm[j].first == p2.first && pm[j].second == p2.second) {
            cout << ans;
            flag = false;
          } // check if it's right square
          else m.push_back(pm[j]);
        } // valid if
      } // for loop: 8 new moves / move
    } // iter through all possible moves
      m.erase(m.begin(), m.begin() + size -1);
  } //true

return 0;
}
