#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, x3, y1, y2, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int AB, AC, BC, m;

    AB = pow(x2-x1, 2) + pow(y2-y1, 2);
    AC = pow(x3-x1, 2) + pow(y3-y1, 2);
    BC = pow(x3-x2, 2) + pow(y3-y2, 2);

    m = min(AB, AC);
    m = min(m, BC);

    cout << m << endl;
    return 0;
}
