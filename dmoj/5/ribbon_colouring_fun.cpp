#include <bits/stdc++.h>

using namespace std;

int r[100005] = {0};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q, x, y;

    cin >> n >> q;

    int blue = 0;

    for(int i = 0; i < q; i++){
        cin >> x >> y;
        r[x]++;
        r[y]--;
    }

    if(r[0] > 0) blue ++;
    for(int i = 1; i < n; i++){
        r[i] += r[i-1];
        if(r[i] > 0) blue ++;
    }

    cout << n - blue << " " << blue << endl;

    return 0;
}
