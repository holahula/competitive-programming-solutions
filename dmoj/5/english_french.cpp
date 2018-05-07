#include <bits/stdc++.h>

using namespace std;

int main() {

  string line;
  vector<string>p;

  int n;

  int ss, cs, st, lt;

  cin >> n;

  ss = 0;
  cs = 0;
  st = 0;
  ct = 0 ;
  for(int i = 0; i < n; i++){
    getline(cin, line);
    p.push_back(line);
    line = "";
  }


  for(int i = 0; i < n; i++){
    cout << p[i] << endl;
  }




    return 0;
}
