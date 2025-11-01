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

    i32 N, L;
    cin >> N >> L;

    if(L % 3 != 0){
        cout << 0 << endl;
        return(0);
    }

    i32 d;
    i32 pos[N + 1];
    pos[1] = 0;
    rep(i, 2, N){
        cin >> d;
        pos[i] = (pos[i - 1] + d) % L;
    }

    i64 cnt[L];
    rep(i, 0, L - 1){
        cnt[i] = 0;
    }
    rep(i, 1, N){
        cnt[pos[i]]++;
    }

    i64 ans = 0;
    rep(l, 0, L / 3 - 1){
        ans += cnt[l] * cnt[l + L / 3] * cnt[l + 2 * L / 3];
    }

    cout << ans << endl;

    return(0);
}
