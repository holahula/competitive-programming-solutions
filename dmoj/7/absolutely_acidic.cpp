#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, r, a, b, diff;
  int s[1005] = {0};
  int ss[1005] = {0};

  vector<int> first, second;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> r;
    s[r]++;
    ss[r]++;
  }

  sort(ss, ss+1005, greater<int>());

  a = ss[0];
  b = ss[1];
  
  for(int i = 0; i <1005; i++){
    if(ss[i] < a) {
      b = ss[i];
      break;
    }
  }

  for(int i = 0; i < 1005; i++){
    if(s[i] == a) first.push_back(i);
    else if (s[i] == b) second.push_back(i);
  }

  if( (int)first.size() > 1) cout << fabs(first.back() - first.front());
  else {
    int f = first.back();
    diff = fabs(f - second[0]);
    for(int i = 1; i < (int)second.size(); i++){
      if(fabs(f - second[i]) > diff){
        diff = fabs(f - second[i]);
      }
    }
    cout << diff;

  }

  return 0;
}
