#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define NMAX 1000005

long long cost[NMAX] = {0};
string w[NMAX];
long long n, k, m, c, x, a, z;
long long mc;
string word;
long long sum = 0;

long long minC[NMAX];

unordered_map<string, int> map;

vector<long long>curr;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> m;

    for(int i = 0; i < n; i++){
        cin >> word;
        w[i] = word;
        map[word] = i;
    }

    for(int i = 0; i < NMAX; i++){
        minC[i] = 99999999999LL;
    }

    for(int i = 0; i < n; i++){
        cin >> c;
        cost[i] = c;
    }

    for(int i = 0; i < k; i++){
        cin >> x;
        mc = 99999999999LL;

        for(int j = 0; j < x; j++){
            cin >> a;
            a -= 1;
            curr.push_back(a);
            if(cost[a] < mc) mc = cost[a];
        }
        for(int l = 0; l < curr.size(); l++){
            minC[curr[l]] = mc;
        }

        curr.clear();
    }



    for(int i = 0; i < m; i++){
        cin >> word;
        sum += minC[map[word]];
    }

    cout << sum << endl;

    return 0;
}
