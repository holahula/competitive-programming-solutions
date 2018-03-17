#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int r, c, k, cx, cy;

    cin >> r >> c >> k;

    int cage[25][25] = {0};

    for(int i = 0; i < k; i++){
        cin >> cx >> cy;
        cage[cx-1][cy-1] = -1;
    }

    cage[r-1][c-1] = 1;

    for(int i = r-1; i > -1; i--){
        for(int j = c-1; j > -1; j--){
            if(cage[i][j] > -1){
                if(cage[i+1][j] > 0 && i+1 < r) cage[i][j] += cage[i+1][j];
                if(cage[i][j+1] > 0 && j+1 < c) cage[i][j] += cage[i][j+1];
            }
        }
    }
    
    cout << cage[0][0] << endl;;

    return 0;
}
