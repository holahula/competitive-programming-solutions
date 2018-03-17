#include <bits/stdc++.h>

using namespace std;

int strokes(int d, vector<int> clubs){
  bool dp[d+5] = {0};
  int distance[d+5] = {0};

  for(int i = 0; i < (int)clubs.size(); i++){
    dp[clubs[i]] = true;
    distance[clubs[i]] = 1;
  }

  dp[0] = true;

  for(int i = clubs[0]; i <= d; i++){

    for(int j = 0; j < (int)clubs.size(); j++){

      if(dp[i-clubs[j]] && i-clubs[j] >= 0){

        dp[i] = true;

        if(distance[i] == 0){
          distance[i] = distance[i-clubs[j]] +1;
        } else if(distance[i-clubs[j]] < distance[i] - 1) {
          distance[i] = distance[i-clubs[j]] +1;
        }

      } // if
    } // for
  } // for

  return distance[d];
}


int main(){
  int d, c, clubDistance, ans; // #1: 1-5280, #2: 1-32
  vector<int> clubs;

  cin >> d >> c;

  for(int i = 0; i < c; i++){
    cin >> clubDistance; // 1-100
    clubs.push_back(clubDistance);
  }

  sort(clubs.begin(), clubs.end());

  ans = strokes(d, clubs);

  if (ans > 0){
    cout << "Roberta wins in " << ans << " strokes." << endl;
  } else {
    cout << "Roberta acknowledges defeat." << endl;
  }


  return 0;
}
