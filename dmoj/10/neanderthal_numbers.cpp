#include <bits/stdc++.h>

using namespace std;

int combinations(string w[], string word, const int len){
    int* dp = new int[len+1];

    for(int i = 0; i <=len; i++) dp[i] = 0;
    dp[0] = 1;

    for(int i = 0; i < len; i++){
        for(int j = 0; j < 10; j++){
            if(word.substr(i, (int)w[j].length()) == w[j] && i + (int)w[j].length() <=len){
                dp[i+(int)w[j].length()] += dp[i];
            }
        }
    }
    return dp[len];
}

int main() {
    string word;
    string w[] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

    for(int i = 0; i < 10; i++){
        cin >> word;
        const int len = (int)word.length();
        cout << combinations(w, word, len) << endl;
    }
}
