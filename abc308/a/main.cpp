// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i < (int)(n); i++)

using namespace std;

int main(){
    int16_t S[8];
    bool answer = true;

    rep(i, 0, 8){
        cin >> S[i];
        if(i != 0 && S[i-1] > S[i]){
            answer = false;
        }
        if(S[i] < 100 || 675 < S[i]){
            answer = false;
        }
        if(S[i] % 25 != 0){
            answer = false;
        }
    }

    if(answer){
        cout << "Yes" << endl;
    } else{
        cout << "No" << endl;
    }
}