#include <string>
#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    int q, x, y, z;
    long long ans;
    bool found;
    int l[2][200005];

    cin >> s >> q;
    l[0][0] = 0;
    l[1][0] = 0;

    for(int i = 0; i < (int)s.length(); i++){
        l[0][i+1] = l[0][i] + (s[i] == '0');
        l[1][i+1] = l[1][i] + (s[i] == '1');
    }

    for(int i = 0; i < q; i++){
        cin >> x >> y >> z;
        found = false;

        if(y > l[z][(int)s.length()] - l[z][x-1]){
            cout << -1 << endl;
        } else {
            ans = lower_bound(l[z] + x , l[z] + s.length() + 1, y + l[z][x-1]) - l[z];
            cout << ans << endl;
        }
    }

    return 0;
}
