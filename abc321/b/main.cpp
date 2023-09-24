// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return(true);
    }
    return(false);
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return(true);
    }
    return(false);
}

int main(){
    cin.tie(nullptr);

    i16 N, X;
    cin >> N >> X;

    vector<i16> A(N - 1);
    rep(i, 0, N - 2){
        cin >> A[i];
    }

    rep(score, 0, 100){
        vector<i16> B = A;
        B.push_back(score);

        i32 sum = 0;
        i16 mina = 100, maxa = 0;
        for(i16 b: B){
            sum += b;
            chmin(mina, b);
            chmax(maxa, b);
        }

        if(sum - mina - maxa >= X){
            cout << score << endl;
            return(0);
        }
    }

    cout << -1 << endl;
    return(0);
}