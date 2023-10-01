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

    i32 N, M;
    cin >> N >> M;

    i32 A[M];
    rep(i, 0, M - 1){
        cin >> A[i];
    }

    rep(d, 1, N){
        i32 ans = lower_bound(A, A + M, d) - A;
        cout << A[ans] - d << endl;
    }

    return(0);
}