#include <bits/stdc++.h>

using namespace std;
  bool poss(int n){
    vector<int>t, b, l;
    int c;
    int cur = 1;
    for(int i = 0; i < n; i++){
      cin >> c;
      t.push_back(c);
    }
    bool flag = true;

    for(int i = 0; i < n; i++){
      if((int)t.size() > 0 && t[(int)t.size()-1] == cur){
        l.push_back(t[(int)t.size()-1]);
        t.pop_back();
      } else if ((int)b.size() > 0 && b[(int)b.size()-1] == cur){
        l.push_back(b[(int)b.size()-1]);
        b.pop_back();
      } else {
        b.push_back(t[(int)t.size()-1]);
        t.pop_back();
      }
      cur ++;
    }

    for(int i = 1; i <= n && flag; i++){
      if(l[i] != i) flag = false;
    }

    return flag;
  }

  int main() {
    int t, n, c;

    cin >> t;

    for(int i = 0; i < t; i++){
      cin >> n;
      cout << poss(n) << "\n";
    }
    return 0;
  }
