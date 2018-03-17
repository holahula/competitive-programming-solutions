#include <iostream>

using namespace std;


int main(){
    int n, total;
    int spaceCounter;
    cin >> total;
    string bin;
    for(int i = 0; i < total; i++){
        cin >> n;

        if(n == 0){
          cout << "0000" << endl;
        } else {
        spaceCounter = 0;
        bin = "";
        while(n > 0){
            bin = to_string(n%2) + bin;
            n /= 2;
            if(((int)bin.length()-spaceCounter) % 4 == 0 && n != 0){
                bin = ' ' + bin;
                spaceCounter++;
            }
        }
        if((int)bin.length() < 4){
            while((int)bin.length()%4 != 0){
                bin = '0' + bin;
            }
        } else if (((int)bin.length() - spaceCounter*5) != 4){
            while(((int)bin.length() - spaceCounter*5) % 4 != 0){
                bin = '0' + bin;
                //cout << "lol" << endl;
            }
        }

        cout << bin << endl;
    }
  }

    return 0;
}
