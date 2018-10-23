#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

string week = "Sun Mon Tue Wed Thr Fri Sat";
string space = " ";
string dspace = "  ";
int day, month;

cin >> month >> day;

cout << week << endl;

for(int i = 1; i < month-1; i++){
  cout << dspace << space;
}

cout << dspace;
int currDay = 1;

int j = 7 - month;

for(currDay; currDay <= j; currDay++){
  if(currDay == j) cout << currDay;
  else cout << currDay << space;
}
cout << endl;
int week = 1;
for(currDay; currDay <= day; currDay++){

  if(week <= 6)cout << currDay << space;
  else cout << currDay;
  week ++;
  if (week == 7){
    week = 1;
    cout << endl;
  }
}
  cout >> endl;
}





    return 0;
}
//
// /Sun Mon Tue Wed Thr Fri Sat
//           1   2   3   4   5
//   6   7   8   9  10  11  12
//  13  14  15  16  17  18  19
//  20  21  22  23  24  25  26
//  27  28  29  30
