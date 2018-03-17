#include <bits/stdc++.h>

using namespace std;

int dark_chocolate(int n, int x, int y, int z){
    bool dp[n+5];
    int split[n+5];
    int smallest = x;

    for (int i = 0; i <= n; i++) {
        dp[i] = false;
        split[i] = 0;
    }

    dp[0] = true; dp[x] = true; dp[y] = true; dp[z] = true;

    split[x] = 1; split[y] = 1; split[z] = 1;



    if (x > y) smallest = y;
    if (smallest > z) smallest = z;

    for (int i = smallest; i <= n; i++){
        if(dp[i-x] && i-x >= 0) {
            dp[i] = true;
            if(split[i-x] >= split[i] && i-x >= 0) split[i] = split[i-x] + 1;
        }
        if(dp[i-y] && i-x >= 0) {
            dp[i] = true;
            if(split[i-y] >= split[i] && i - y >= 0) split[i] = split[i-y] + 1;
        }
        if(dp[i-z] && i-z >= 0) {
            dp[i] = true;
            if(split[i-z] >= split[i] && i-z >= 0) split[i] = split[i-z] + 1;
        }
    } // for
    return split[n];
}


int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << dark_chocolate(n, x, y, z) << endl;;
    return 0;
}
