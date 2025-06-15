// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

// 3^14 以上の数
#define MAX 5'000'000

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

i16 N;
string S;

// sum[d]: 深さdまでの頂点の総数
i32 sum[15];
// dp[v][i]: 頂点vにおいてをiにするための最小コスト
i32 dp[MAX][2];

void dfs(i32 v, i16 depth);

int main(){
    cin.tie(nullptr);

    cin >> N >> S;

    i32 p = 1;
    sum[0] = 1;
    rep(i, 1, 13){
        p *= 3;
        sum[i] = sum[i - 1] + p;
    }

    dfs(0, 0);

    cout << max(dp[0][0], dp[0][1]) << endl;

    return(0);
}

void dfs(i32 v, i16 depth){
    if(N <= depth){
        i32 idx = v - sum[depth - 1];
        if(S[idx] == '0'){
            dp[v][0] = 0;
            dp[v][1] = 1;
        } else if(S[idx] == '1'){
            dp[v][0] = 1;
            dp[v][1] = 0;
        }
        return;
    }

    dfs(3 * v + 1, depth + 1);
    dfs(3 * v + 2, depth + 1);
    dfs(3 * v + 3, depth + 1);

    dp[v][0] = INT32_MAX;
    dp[v][1] = INT32_MAX;

    rep(i, 0, 7){
        i32 cost = 0;
        rep(j, 0, 2){
            if((i >> (2 - j)) & 1){
                cost += dp[3 * v + j + 1][1];
            } else{
                cost += dp[3 * v + j + 1][0];
            }
        }

        i32 popcnt = __builtin_popcount(i);

        if(popcnt < 2){
            dp[v][0] = min(dp[v][0], cost);
        } else{
            dp[v][1] = min(dp[v][1], cost);
        }
    }

    return;
}
