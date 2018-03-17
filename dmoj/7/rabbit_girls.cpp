#include <bits/stdc++.h>

using namespace std;

int rabbit(int n, int k){
  if(k >= n) return k - n;
  else return min(n % k, k-(n%k));
}



int main() {
  long long n, k; //1 <= n, k <= 2*10^9
  cin >> n >> k;
  cout << rabbit(n, k) << endl;
    return 0;
}
