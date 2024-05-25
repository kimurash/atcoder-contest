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

    i16 N;
    cin >> N;

    string S;
    cin >> S;

    rep(i, 0, N -3){
        if(S.substr(i, 3) == "ABC"){
            cout << i + 1 << endl;
            return(0);
        }
    }

    cout << -1 << endl;
    return(0);
}