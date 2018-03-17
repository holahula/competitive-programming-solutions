#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t[1000005];
    int sum[1000005] = {0};
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q, a, b, l;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> l;
        t[i] = l;

    }

    sum[0] = t[0];
    
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + t[i];
    }

    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(a == 0) cout << sum[b] << "\n";
        else cout << sum[b]-sum[a-1] <<"\n";
    }

    return 0;
}
