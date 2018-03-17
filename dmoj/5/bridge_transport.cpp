#include <bits/stdc++.h>

using namespace std;

  int pass (int w, int n){
    int* cars = new int [n];
    int car;
    int ans = 0;

    for(int i = 0; i < n; i++){
      cin >> car;
      cars[i] = car;
    }

    for(int i = 0; i < n-3; i++){
        int c1, c2, c3, c4;

        c1 = cars[i];
        c2 = cars[i+1];
        c3 = cars[i+2];
        c4 = cars[i+3];

        if(c1 + c2 + c3 + c4 > w) break;
        else ans ++;
      }

    return ans + 3;
  }

  int main() {

    int w, n, ans;
    cin >> w >> n;

    ans = pass(w, n);

    cout << ans << endl;
    return 0;
  }
