#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
#define MAX 100001
//          31622776
ll spf[MAX];

ll gcd(ll a, ll b){
    return b==0 ? a : gcd(b,a%b);
}

ll calcGCD(vector<ll> arr){
    ll left, right;

    size_t const half_size = arr.size() / 2;
    vector<ll> lo(arr.begin(), arr.begin() + half_size);
    vector<ll> hi(arr.begin()+half_size, arr.end());

    if(arr.size() == 1){
        return arr[0];
    } else if(arr.size() == 2){
        return gcd(arr[0], arr[1]);
    } else {
        left = calcGCD(lo);
        right = calcGCD(hi);
    }
    return gcd(left, right);
}


ll factorize(ll x){

    ll ans = 1;

    for(ll i = 2; i <= (ll)sqrt(x); i++){
        if(x % i == 0) ans = max(ans, i);
        while (x % i == 0) x /= i;
    }
    return max(ans, x);
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll a, gcd;

    vector<ll> arr;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        arr.push_back(a);
    }
    gcd = calcGCD(arr);

    if(gcd == 1){
        cout << "DNE" << endl;
    } else {
        cout << factorize(gcd) << endl;
    }
    return 0;
}
