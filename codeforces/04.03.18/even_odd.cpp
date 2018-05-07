#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    //    if(n == 1){
    //        cout << "Ehab" << endl;
    //    } //else if(n == 2) cout << "Mahmoud" << endl;
    //    else if(n % 2 == 0){
    //        cout << "Mahmoud" << endl;
    //    } else {
    //        cout << "Ehab" << endl;
    //    }

    if(n % 2 == 1){
        cout << "Ehab" << endl;
    } else {
        cout << "Mahmoud" << endl;
    }



    return 0;
}
