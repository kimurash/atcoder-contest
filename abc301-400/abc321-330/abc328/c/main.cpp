// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i32 N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    i32 acc[N] = {0};
    rep(i, 1, N - 1){
        acc[i] = acc[i - 1] + (S[i - 1] == S[i]);
    }

    i32 l, r;
    rep(i, 1, Q){
        cin >> l >> r;
        cout << acc[r - 1] - acc[l - 1] << endl;
    }

    return(0);
}