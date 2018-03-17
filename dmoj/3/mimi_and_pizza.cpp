#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int b, p;
    string a;
    cin >> b >> p >> a;

    if(a == "Y"){
      if(b > 5*p){
        cout << "B";
      }  else if (b > 2 * p){
        cout << "D";
      } else {
        cout << "NO PIZZA";
      }
    } else {
      if(b > 5*p){
        cout <<"A";
      } else if (b > 2*p){
        cout << "C";
      } else {
          cout << "NO PIZZA";
      }
    }

    return 0;
}
