#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string inp;
    vector<int> n;
    int adj = 1;

    cin >> N;

    int tot = N;
    for(int i = 0; i < N; i++){
      cin >> inp;
      if(inp[0] >= 97) n.push_back(inp[0] - 97);
      else n.push_back(inp[0] - 65);
    }

    for(int i = 0; i < (N-1); i++){
      if(n[i] == n[i+1]){
        adj ++;
      } else {
        tot += (adj * (adj-1))/2;
        adj = 1;
      }
    }
   tot += (adj * (adj-1))/2;


    cout << tot % 1000000007;
    return 0;
}
