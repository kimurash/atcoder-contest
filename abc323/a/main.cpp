// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
// #define all(v) v.begin(), v.end()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    string S;
    cin >> S;

    for(int i = 1; i < S.size(); i += 2){
        if(S[i] != '0'){
            cout << "No" << endl;
            return(0);
        }
    }

    cout << "Yes" << endl;
    return(0);
}