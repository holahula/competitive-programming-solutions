#include <bits/stdc++.h>

using namespace std;



int main() {
    int n, c;
    //vector<int> pos, neg;
    int pS = 0;
    int nS = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
      cin >> c;

      if(c >= 0){
        pS += c;
      } else {
        nS += c;
      }

    }

    cout << pS - nS << endl;

    return 0;
}
