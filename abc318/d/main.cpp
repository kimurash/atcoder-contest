// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

#define MAX 16

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// dp[S]: 集合Sに含まれる頂点を結ぶ辺を選んだ時の重みの総和の最大値
i64 dp[1 << MAX];

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 D[N][N];
    rep(i, 0, N - 2){
        rep(j, i + 1, N - 1){
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    i64 answer = 0;
    rep(b, 0, 1 << N - 1){ // O(2^N)
        rep(i, 0, N - 2){ // O(N)
            rep(j, i + 1, N - 1){ // O(N)
                if((b & (1 << i)) == 0 && (b & (1 << j)) == 0){
                    i32 next = b | (1 << i) | (1 << j);
                    dp[next] = max(dp[next], dp[b] + D[i][j]);
                    answer = max(answer, dp[next]);
                }
            }
        }
    }

    cout << answer << endl;
    return(0);
}