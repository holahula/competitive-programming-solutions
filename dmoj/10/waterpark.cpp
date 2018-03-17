#include <iostream>
#include <vector>

using namespace std;

int sliding(int n, vector<vector<int>> slide){
    int dp[10005] = {0};

    dp[n] = 1;

    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < (int)slide[i].size(); j++){
            dp[i]+=dp[slide[i][j]];
        }
    }
    return dp[1];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);

    int n, x, y;

    cin >> n;

    vector< vector<int> > slide(n+1);

    while(x != 0 && y != 0){
        cin >> x >> y;
        slide[x].push_back(y);
    }

    cout << sliding(n, slide);
    return 0;
}
