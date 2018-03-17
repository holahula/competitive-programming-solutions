#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > tr(1005);
vector<int> w, visited, weights;

bool visited[1005] = {0};

void dfs(int at, int prev, int b){

    weights.push_back(w[at]);
    visited[at] = true;

    if(at == b){ // end call
        return;
    }

    if(tr[at].size() == 1 && tr[at][0] == prev){ // end node and != b
        weights.pop_back();
        return;
    }

    for(int i = 0; i < tr[at].size(); i++){
        if(!visited(tr[at][i]) dfs(tr[at][i], at, b);
            //if(visited.size() > weights.size()) weights.pop_back();
        }
    }
}

int avg(vector<int> ans, int q){
    int freq[100005] = {0};
    vector<int> mode;
    int answer = 0;
    double sum = 0;

    if(q == 1){ // mean
        for(int i = 0; i < ans.size(); i++){
            sum += ans[i];
        }
        answer = (int)round(sum / (double)ans.size());

    } else if (q == 2){ // median
        sort(ans.begin(), ans.end());
        if(ans.size() % 2 == 1){
            answer = ans[ans.size()/2];
        } else {
            answer = (int)ceil(((double)ans[ans.size()/2] + (double)ans[ans.size()/2-1])/2);
        }
    } else { // mode
        for(int i = 0; i < ans.size(); i++) freq[ans[i]]++;

        int max = freq[0];

        for(int i = 0; i < 100005; i++){
            if(freq[i] > max) max = freq[i];
        }
        for(int i = 0; i < 100005; i++){
            if(freq[i] == max) mode.push_back(i);
        }
        sort(mode.begin(), mode.end());
        answer = mode[0];
    }

    return answer;
}

// each vector has 2 elements: #1 = val, #2 = path
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, q, val, qu;

    cin >> n >> q;

    w.push_back(0);

    for(int i = 0; i < n; i++){
        cin >> val;
        w.push_back(val);
    }

    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    for(int i = 0; i < q; i++){
        cin >> qu >> a >> b;
        dfs(a, 0, b);

//        for(int i = 0; i <w.size(); i++){
//            cout << "i: " <<  w[i] << endl;
//        }
//        cout << "weight size: " << weights.size() << endl;
//        for(int i = 0; i < weights.size(); i++){
//            cout << weights[i] << endl;
//        }

        cout << avg(weights, qu) << endl;
        weights.clear();
        visited.clear();
    }


    return 0;
}
