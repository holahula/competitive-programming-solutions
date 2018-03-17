#include <bits/stdc++.h>

using namespace std;

int prime(int n){
  bool prime = true;
  int bp = floor(sqrt(n));
  vector<int>primes;
  primes.push_back(1);
  primes.push_back(2);

  for(int i = 3; i <=bp; i++){
    for(int j = 2; j < i; j++){
      if(i % j == 0) prime = false;
    }
    if(prime) primes.push_back(i);
    else prime = true;
  }

  prime = true;

  while(prime){
    for(int i = 0; i < (int)primes.size() && prime; i++){
      if(n%primes[i] == 0) prime = false;
    }
    if(!prime) {
      prime = true;
      n++;
    } else {
      prime = false;
    }
  }
  return n;
}

int main(){
    int n;
    cin >> n;
    cout << prime(n) << endl;;
    return 0;
}
