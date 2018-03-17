#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int in, s; //in = original # of students, s = # of students transfering
    int m;
    int initSum = 0;
    double ans;

    cin >> in;

    for(int x = 0; x < in; x++){
        cin >> m;
        initSum += m;
    }

    cin >> s;

    for(int i = 0; i < s; i++){
        cin >> m;
        initSum += m;
        ans = initSum / (double)(i+in+1);
        printf("%.3f\n", ans);
    }

    return 0;
}
