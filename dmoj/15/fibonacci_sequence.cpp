#include <bits/stdc++.h>

using namespace std;

#define m 1000000007

typedef pair <long long int, long long int> plli;
typedef unsigned long long int ulli;
typedef long long int lli;

plli fib(ulli n){
  lli a, b, c, d;
  plli ans;

  if(n == 0){
    ans = make_pair(0, 1);
    return ans;
  }

  ans = fib(n/2);

  a = ans.first;
  b = ans.second;

  c = (a * (2 * b - a + m)) % m;

  d = (a*a)%m + (b*b)%m;

  if(n % 2 == 0) ans = make_pair(c%m, d%m);
  else ans = make_pair(d%m, (c+d)%m);

  return ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ulli n;
    cin >> n;
    cout << fib(n).first << endl;

    return 0;
}
