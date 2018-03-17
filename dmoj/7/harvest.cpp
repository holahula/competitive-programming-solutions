#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll a, b, n, m, k, sum;

    ll miss[200005] = {0};
    ll pot[200005] = {0};

    vector <ll> width;

    cin >> n >> m >> k;

    if(k == 0){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b;
        miss[a-1]--;
        miss[b]++;
    }

    pot[0] = m;

    for(int i = 1; i <= n; i++) pot[i] = pot[i-1] + miss[i-1];

    a = 1; b = 1;
    sum = pot[1];

    while(b <= n){
        if(sum >= k){
            width.push_back(b-a+1);
            sum -= pot[a];
            a++;
            if(a > b) break;
        } else {
            b++;
            sum += pot[b];
        }
    }

    if(width.empty()) cout << -1 << endl;
    else {
        sort(width.begin(), width.end());
        cout << width[0] << endl;
    }

    return 0;
}
