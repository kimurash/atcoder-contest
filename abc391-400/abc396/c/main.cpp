// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N, M;
    cin >> N >> M;

    i32 B[N + 1];
    rep(i, 1, N){
        cin >> B[i];
    }

    i32 W[M + 1];
    rep(i, 1, M){
        cin >> W[i];
    }

    sort(B + 1, B + N + 1, greater<i32>());
    sort(W + 1, W + M + 1, greater<i32>());

    i64 accb[N + 1] = {0};
    rep(i, 1, N){
        accb[i] = accb[i - 1] + B[i];
    }
    i64 accw[M + 1] = {0};
    i64 maxw[M + 1] = {0};
    rep(i, 1, M){
        accw[i] = accw[i - 1] + W[i];
        maxw[i] = max(maxw[i - 1], accw[i]);
    }

    i64 ans = 0;
    rep(i, 0, N){
        ans = max(ans, accb[i] + maxw[min(i, M)]);
    }

    cout << ans << endl;
    return(0);
}
