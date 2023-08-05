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

    i16 P1, P, maxp = 0;
    cin >> P1;

    rep(i, 2, N){
        cin >> P;
        maxp = max(maxp, P);
    }

    if(maxp < P1){
        cout << 0 << endl;
    } else{
        cout << maxp + 1 - P1 << endl;
    }

    return(0);
}