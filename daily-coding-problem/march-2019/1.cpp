#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int inp[];
    bool outp[] = {0};
    int k, id;

    for(int i = 0; i < inp.size(). i++){
        id = inp[i] % k;

        if(outp[k-id]) return true;
        else outp[id] = true;
    }

    return 0;
}
