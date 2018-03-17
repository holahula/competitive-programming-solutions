#include <bits/stdc++.h>
#include <string>

using namespace std;

int crossing(int m, int q, vector<string>n; vector<int> p){
  // m = size, q = # of people / group, n = names, p = time / person
  vector<int>groups;
  int grpSize = 0;
  int* dp = new int[q+1];

  for(int i = 0; i < q; i++){
    dp[i] = 0;
  }
  // 1 person;
  dp[0] = p[0];
  grpSize++;


  for(int i = 1; i < q; i++){
    if(p[i] > dp[i-1]){
      dp[i] = p[i];
    } else {
      dp[i] = p[i-1];
    }
  }




}

  int main() {
    int m, q, p; // 1 <= size <= 20, 1 <= # <= 100
    string n;
    vector<int>pos;
    vector<string>name;


    for(int i = 0; i < q; i++){
      cin >> n, p;
      pos.push_back(p);
      name.push_back(n);
    }

    crossing(m, q, n, p);
    return 0;
  }


/*
  // 3 people:

  1 / 2 / 3
  1 / 2 3
  1 2 / 3
*/
