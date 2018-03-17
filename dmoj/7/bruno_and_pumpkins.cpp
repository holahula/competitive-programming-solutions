#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    vector<int>pumpkins, ans;
    int n, t, itr, steps;
    int a, b;

    cin >> n >> t;

    for(int i = 0; i < n; i++){
        cin >> itr;
        pumpkins.push_back(itr);

    }

    sort(pumpkins.begin(), pumpkins.end());
        for(int i = 0; i < n-t+1; i++){
        a = fabs(pumpkins[i]) + fabs(pumpkins[i+t-1]-pumpkins[i]);
        b = fabs(pumpkins[i+t-1]) + fabs(pumpkins[i]-pumpkins[i+t-1]);
        steps = min(a, b);
        ans.push_back(steps);
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << endl;

    return 0;
}
