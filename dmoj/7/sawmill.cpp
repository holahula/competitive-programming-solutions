#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long s;
  long long sum = 0;
  cin >> n;
  vector<long long> e, l;

  for(int i = 0; i < n; i++){
    cin >> s;
    e.push_back(s);
  }

  for(int i = 0; i < n; i++){
    cin >> s;
    l.push_back(s);
  }

  sort(e.begin(), e.end());
  sort(l.begin(), l.end(), greater<int>());

  for(int i = 0; i < n; i++){
    sum += (e[i] * l[i]);
  }

  cout << sum << endl;
    return 0;
}
