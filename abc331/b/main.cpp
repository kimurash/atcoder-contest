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

    i32 N, S, M, L;
    cin >> N >> S >> M >> L;

    i32 s = 100 / 6 + 1;
    i32 m = 100 / 8 + 1;
    i32 l = 100 / 12 + 1;

    i32 ans = INT32_MAX;
    rep(i, 0, s){
        rep(j, 0, m){
            rep(k, 0, l){
                if(6 * i + 8 * j + 12 * k >= N){
                    ans = min(ans, S * i + M * j + L * k);
                }
            }
        }
    }

    cout << ans << endl;
    return(0);
}