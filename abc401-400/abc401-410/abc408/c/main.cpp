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

    i32 L, R;
    i32 wall[N + 2] = {0};
    rep(i, 1, M){
        cin >> L >> R;
        wall[L]++;
        wall[R + 1]--;
    }

    i32 acc[N + 2] = {0};
    rep(i, 1, N){
        acc[i] = acc[i - 1] + wall[i];
    }

    i32 ans = M;
    rep(i, 1, N){
        ans = min(ans, acc[i]);
    }

    cout << ans << endl;

    return(0);
}
