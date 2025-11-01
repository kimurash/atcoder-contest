// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define INF 200'009

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, D;
    cin >> N >> D;

    if(D == 0){
        i32 A;
        set<i32> S;
        rep(i, 1, N){
            cin >> A;
            S.insert(A);
        }
        cout << N - S.size() << endl;
    } else{
        i32 A;
        vi32 group[D];

        rep(i, 1, N){
            cin >> A;
            group[A % D].push_back(A);
        }

        i64 total = 0;

        rep(d, 0, D - 1){
            if(group[d].empty()){
                continue;
            }

            map<i32, i32> mp;
            for(i32 a : group[d]){
                mp[a]++;
            }

            i32 size = mp.size();

            // dp[i][j]: i番目までの要素から選択できる要素の最大個数
            // j = 1: i番目の要素を使う
            // j = 0: i番目の要素を使わない
            i32 dp[size + 1][2];
            dp[0][0] = 0;
            dp[0][1] = -INF;

            i32 i = 1;
            i32 prev = -1;
            for(auto [v, cnt] : mp){
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

                if(i == 1){
                    dp[i][1] = dp[i - 1][0] + cnt;
                } else{
                    if(v == prev + D){
                        dp[i][1] = dp[i - 1][0] + cnt;
                    } else{
                        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + cnt;
                    }
                }

                i++;
                prev = v;
            }
            total += max(dp[size][0], dp[size][1]);
        }
        cout << N - total << endl;
    }

    return(0);
}
