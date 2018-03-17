#include <bits/stdc++.h>

#define MAX 1000005
#define MOD 1000000007

using namespace std;

bool ab[MAX];

void pre(){
    int num, m;
    ab[1] = true;
    for(int i = 2; i * i <= MAX; i++){
        m = 2;
        while(pow(i, m) < MAX){
            num = pow(i, m);
            ab[num] = true;
            m++;
        }
    }
}

int fx(int n){
    if(ab[n]) return n;
    else return 0;
}

int tot(int n){
    double ans = n;

    if(n % 2 == 0){
        while(n % 2 == 0) n /= 2;
        ans *= 0.5;
    }

    for(int i = 3; i*i <= n; i+= 2){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            ans *= (1.0 - (1.0 / (double)i ));
        }
    }

    if(n > 1) ans *= (1.0 - (1.0 / (double)n ));
    return (int) ans;

}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    int ans = 0;

    cin >> n;

    pre();

    for(int i = 1; i <= n; i++){
        ans += fx(tot(i));
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
//
