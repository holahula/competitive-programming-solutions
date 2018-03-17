#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string w;
    int l;

    cin >> w;

    l = (int)w.length();

    for(int i = 0; i < l; i++){
      if(w[i] == '0') w[i] = 'O';
      else if (w[i] == '1') w[i] = 'l';
      else if (w[i] == '3') w[i] = 'E';
      else if (w[i] == '4') w[i] = 'A';
      else if (w[i] == '5') w[i] = 'S';
      else if (w[i] == '6') w[i] = 'G';
      else if (w[i] == '8') w[i] = 'B';
      else if (w[i] == '9') w[i] = 'g';
    }
    cout << w << endl;


    return 0;
}
