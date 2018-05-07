#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;



int main() {
    vector<int> a, b;

    int q, n, curr, minimum, maximum;

    cin >> q >> n;


    for(int i = 0; i < n; i++){
        cin >> curr;
        a.push_back(curr);
    }

    for(int i = 0; i < n; i++){
        cin >> curr;
        b.push_back(curr);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    minimum = 0;
    maximum = 0;

    for(int i = 0; i < n; i++){
        minimum += max(a[i], b[i]);
        maximum += max(a[i], b[n-1-i]);
    }

    if(q == 1){
        cout << minimum << endl;
    } else {
        cout << maximum << endl;
    }
    return 0;
}
