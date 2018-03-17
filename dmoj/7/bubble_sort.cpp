#include <bits/stdc++.h>

using namespace std;

void print(int arr[], int N){
  for(int i  = 0; i < N; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {

  int N, n, swap;
  int arr[20];

  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> n;
    arr[i] = n;
  }

  print(arr, N);

  for(int i =  0; i < N-1; i++){
    for(int j = 0; j < N-i-1; j++){
      if(arr[j] > arr[j+1]){
        swap = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = swap;

        print(arr, N);
      }
    }
  }
  return 0;
}
