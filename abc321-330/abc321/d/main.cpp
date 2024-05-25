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

    i64 N, M, P;
    cin >> N >> M >> P;

    i64 A[N], B[M];
    rep(i, 0, N - 1){
        cin >> A[i];
    }
    rep(i, 0, M - 1){
        cin >> B[i];
    }

    sort(B, B + M);

    i64 accb[M];
    accb[0] = B[0];
    rep(i, 1, M - 1){
        accb[i] = B[i] + accb[i - 1];
    }

    i64 ans = 0;
    rep(i, 0, N - 1){
        if(A[i] < P){
            i64 rem = P - A[i];
            i64 pos = lower_bound(B, B + M, rem) - B;
            if(pos == 0){
                ans += P * M;
            } else{
                ans += A[i] * pos + accb[pos - 1] + P * (M - pos);
            }
        } else{ // A[i] >= P
            ans += P * M;
        }
    }

    cout << ans << endl;
    return(0);
}