// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define INF 1e11 + 9 // > 10^9 * 100
#define MAXN 109
#define MAXPRM 7780 // > (5 + 1)^6 = 7776

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

template <typename T>
bool chmin(T &a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

// dp[i][j]: i番目までの開発案を用いてパラメータをjにするための最小コスト
i64 dp[MAXN][MAXPRM];

int main(){
    cin.tie(nullptr);

    i16 N, K, P;
    cin >> N >> K >> P;

    i64 pow[K + 1];
    pow[0] = 1;
    rep(i, 1, K){
        pow[i] = pow[i - 1] * (P + 1);
    }

    i32 cost[N + 1];
    i16 A[N + 1][K];
    rep(i, 1, N){
        cin >> cost[i];

        for(int k = K - 1; k >= 0; k--){
            cin >> A[i][k];
        }
    }

    dp[0][0] = 0;
    rep(j, 1, pow[K] - 1){
        dp[0][j] = INF;
    }

    rep(i, 0, N - 1){
        // 次の列を初期化する
        rep(j, 0, pow[K] - 1){
            dp[i + 1][j] = INF;
        }

        rep(j, 0, pow[K] - 1){
            // i番目の開発案を使わない
            chmin(dp[i + 1][j], dp[i][j]);

            // 次状態を求める
            i16 digit;
            i64 src = j, dst = 0;
            rep(k, 0, K - 1){
                digit = src % (P + 1);
                digit = min(digit + A[i + 1][k], 1 * P); // 型を揃えるために1をかける
                dst += digit * pow[k];

                src /= (P + 1);
            }

            // i番目の開発案を使う
            chmin(dp[i + 1][dst], dp[i][j] + cost[i + 1]);
        }
    }

    cout << (dp[N][pow[K] - 1] != INF ? dp[N][pow[K] - 1] : -1) << endl;
    return(0);
}