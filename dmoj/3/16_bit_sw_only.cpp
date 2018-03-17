#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll a, b, p;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> p;
        if(a * b == p){
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;
        }
    }
    return 0;
}
