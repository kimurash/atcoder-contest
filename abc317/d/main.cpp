// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

int main(){
    cin.tie(nullptr);

    i16 N;
    cin >> N;

    i32 chair_sum = 0;
    i32 X[N + 1], Y[N + 1], Z[N + 1];
    rep(i, 1, N){
        cin >> X[i] >> Y[i] >> Z[i];
        chair_sum += Z[i];
    }

    i64 dp[chair_sum + 1];
    dp[0] = 0;
    rep(i, 1, chair_sum){
        dp[i] = 1e11;
    }

    rep(i, 1, N){
        i32 rev = max(0, (Y[i] - X[i]) / 2 + 1);
        for(i32 j = chair_sum; j >= Z[i]; j--){
            dp[j] = min(dp[j], dp[j - Z[i]] + rev);
        }
    }

    i64 answer = 1e11;
    rep(i, chair_sum / 2 + 1, chair_sum){
        answer = min(answer, dp[i]);
    }

    cout << answer << endl;
    return(0);
}