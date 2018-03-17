#include <iostream>

using namespace std;


int main(){
    int n, total;
    cin >> total;
    string bin;
    for(int i = 0; i < total; i++){
        cin >> n;
        if(n == 0){
            cout << "0000" << endl;
        } else {
        bin = "";
        while(n > 0){
            //cout << n << endl;
            bin = to_string(n%2) + bin;
            n /= 2;
        }
        while((int)bin.length()%4 != 0){
            bin = '0' + bin;
        }
        cout << bin << endl;
    }
    }

    return 0;
}
