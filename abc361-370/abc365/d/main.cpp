// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i64 N;
    cin >> N;

    string S;
    cin >> S;

    // dp[i][j] = i回目にjを出した時の最大勝利数
    i64  dp[N + 1][4];
    rep(i, 0, N){
        rep(j, 1, 3){
            dp[i][j] = 0;
        }
    }

    rep(i, 1, N){
        char aoki = S[i - 1];
        rep(j, 1, 3){
            if(j == ROCK){
                dp[i][j] = max(dp[i - 1][PAPER], dp[i - 1][SCISSORS]);
                if(aoki == 'S'){
                    dp[i][j]++;
                } else if(aoki == 'P'){
                    dp[i][j] = 0;
                }
            } else if(j == PAPER){
                dp[i][j] = max(dp[i - 1][ROCK], dp[i - 1][SCISSORS]);
                if(aoki == 'R'){
                    dp[i][j]++;
                } else if(aoki == 'S'){
                    dp[i][j] = 0;
                }
            } else if(j == SCISSORS){
                dp[i][j] = max(dp[i - 1][ROCK], dp[i - 1][PAPER]);
                if(aoki == 'P'){
                    dp[i][j]++;
                } else if(aoki == 'R'){
                    dp[i][j] = 0;
                }
            }
        }
    }

    cout << max({dp[N][ROCK], dp[N][PAPER], dp[N][SCISSORS]}) << endl;
    return(0);
}
