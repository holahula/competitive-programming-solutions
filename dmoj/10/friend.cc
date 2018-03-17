#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pi;
typedef map <int, int> mi;

mi::iterator i1;

pi friend_finder(mi f, int a, int b){
    int c = 0;
    bool seen[10005] = {0};

    i1 = f.find(a);

    while(!seen[a] && !seen[b]){
        seen[i1->second] = true;
        c++;
        i1=f.find(i1->second);
    }
    pi answer = pi(seen[b], c-1);
    return answer;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    mi f;
    int n, x, y, a, b;
    pi a1, a2;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x >> y;
        f.insert(pi(x,y));
    }

    while(true){
        cin >> a >> b;

        if(!a && !b){
            break;
        } else {
            a1 = friend_finder(f, a, b);
            if(a1.first) cout << "Yes " << a1.second << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
