// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/modint>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;
using mint = atcoder::modint998244353;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

const int MOD = 998244353;

bool is_palindrome(const string &S) {
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

int main() {
    i32 N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    // DP テーブルの初期化
    map<string, i64> dp1;
    dp1[string(K - 1, 'C')] = 1;

    for (char c : S) {
        map<string, i64> dp2;

        // 'A' を追加する場合
        if (c != 'B') {
            for (auto &entry : dp1) {
                string new_str = entry.first + 'A';
                string suffix = new_str.substr(1);
                string substr = new_str.substr(new_str.size() - K);
                if (!is_palindrome(substr)) {
                    dp2[suffix] = (dp2[suffix] + entry.second) % MOD;
                }
            }
        }

        // 'B' を追加する場合
        if (c != 'A') {
            for (auto &entry : dp1) {
                string new_str = entry.first + 'B';
                string suffix = new_str.substr(1);
                string substr = new_str.substr(new_str.size() - K);
                if (!is_palindrome(substr)) {
                    dp2[suffix] = (dp2[suffix] + entry.second) % MOD;
                }
            }
        }

        // DP テーブルを更新
        dp1 = dp2;
    }

    // 良い文字列の数を集計
    i64 result = 0;
    for (auto &entry : dp1) {
        result = (result + entry.second) % MOD;
    }

    cout << result << endl;

    return(0);
}
