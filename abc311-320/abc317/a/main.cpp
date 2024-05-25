// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N, H, X;
    cin >> N >> H >> X;

    i16 P[N + 1];
    rep(i, 1, N){
        cin >> P[i];
    }

    rep(i, 1, N){
        if(X <= H + P[i]){
            cout << i << endl;
            break;
        }
    }

    return(0);
}