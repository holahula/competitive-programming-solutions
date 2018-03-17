#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    unsigned long long N, n, fact;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        fact = 1;
        cin >> n;
        if(n >= 34) cout << 0 << endl;
        else {
        for(long long i = n; i > 1; i--){
            fact *= i;
            fact %= 4294967296;
        }
        cout << fact << endl;
        }
    }
    return 0;
}
