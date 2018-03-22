#include <bits/stdc++.h>

using namespace std;

long double n, a, b;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;
    cout << fixed << setprecision(10);
    cout << (-b / n / a);

    return 0;
}
