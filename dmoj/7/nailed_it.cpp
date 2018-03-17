#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nail(int logs[]){
    const int M = 2005;
    const int N = 4005;
    int len[N] = {0};
    vector<int> ans;
    int a = 0, b = 0;

    for(int i = 1; i < M; i++){
        if(logs[i] > 0){
            for(int j = i; j < M; j++){
                if(i == j) len[i+j] += logs[i]/2;
                else if(logs[j] > 0) len[i+j] += min(logs[i], logs[j]);
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        if(len[i] > a) {
            a = len[i];
            b=1;
        }
        else if(len[i] == a){
            b++;
        }
    }

    ans.push_back(a);
    ans.push_back(b);

    return ans;
}


int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, l; // 1 <= l <= 2000
    vector<int> ans;
    int logs[2005] = {0};

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> l;
        logs[l] ++;
    }

    ans = nail(logs);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
