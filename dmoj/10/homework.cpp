#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

#define MAX 10000005

int spf[MAX];
int npf[MAX] = {0};

void sieve(){

    spf[1] = 1;

    for(int i = 2; i < MAX; i++){
        if(i%2 == 0) spf[i] = 2;
        else spf[i] = i;
    }

    for(int i = 3; i*i < MAX; i++){
        if(spf[i] == i){
            for(int j = i * i; j < MAX; j+= i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void factorize(int x){
    int num = x;
    int currSPF;
    while(x != 1){
        npf[num] ++;
        currSPF = spf[x];
        while(x % currSPF == 0) x /= currSPF;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, k;
    cin >> t;

    sieve();

    for(int i = 2; i < MAX; i++) factorize(i);


    for(int i = 0; i < t; i++){
        int ans = 0;
        cin >> a >> b >> k;

        for(int i = a; i <= b; i++){
            if(npf[i] == k) ans++;
        }
        cout << "Case #"<< i+1 << ": " << ans << endl;
    }

    return 0;
}
