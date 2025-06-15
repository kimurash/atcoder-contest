// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

#define MAX 200'009

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

    i32 rl[MAX];
    rep(i, 1, M){
        rl[i] = M;
    }

    i32 L, R;
    rep(i, 1, N){
        cin >> L >> R;
        rl[L] = min(rl[L], R - 1);
    }

    i64 ans = 0;
    i32 minr = M;
    for(int i = M; 0 < i; i--){
        minr = min(minr, rl[i]);
        ans += minr - i + 1;
    }

    cout << ans << endl;
    return(0);
}
