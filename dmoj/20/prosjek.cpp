#include <bits/stdc++.h>

using namespace std;

#define NMAX 300005

int n, k;

long double num[NMAX] = {0};
long double ps[NMAX] = {0};
long double msum[NMAX] = {0};

bool exist(long double avg){
    bool poss = false;
    long double sum, cmax;

    for(int i = 0; i < n; i++) ps[i] = num[i] - avg;

    cmax = ps[0];
    msum[0] = ps[0];

    for(int i = 1; i < n; i++){ //maximum possible sum ending at [i] (add to prev sum / start new)
        cmax = max(ps[i], cmax + ps[i]);
        msum[i] = cmax;
    }

    sum = 0;

    for(int i = 0; i < k; i++) sum += ps[i];

    long double result = sum; // starting sum

    for(int i = k; i < n; i++){
        sum = sum + ps[i] - ps[i-k];
        result = max(sum, result);
        result = max(result, sum + msum[i-k]);
    }

    if(result >= 0) poss = true;

    return poss;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    long double a;

    for(int i = 0; i < n; i++){
        cin >> a;
        num[i] = a;
    }

    long double min, mid, max;

    min = 0; max = 2e6;

    while(max-min > 1e-6){
        mid = (min+max)/2;
        if(exist(mid)) min = mid;
        else max = mid;
    }

    printf("%.6lf\n", (double)(min+max)/2);
    return 0;
}
