// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    string T[] = {
        "ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"
    };

    rep(i, 0, 6){
        if(S == T[i]){
            cout << "Yes" << endl;
            return(0);
        }
    }

    cout << "No" << endl;
    return(0);
}