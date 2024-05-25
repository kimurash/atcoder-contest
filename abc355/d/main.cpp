// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define rep(i, s, n) for (int i = s; i <= (int)(n); i++)
#define  all(v) v.begin(),  v.end()
#define rall(v) v.rbegin(), v.rend()
#define arrout(a, s, n) rep(i, s, n)cout<<a[i]<<" "; cout<<endl;
#define vecout(v) for(auto elm : (v))cout<<elm<<" "; cout<<endl;

using namespace std;

typedef string str;

typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef vector<i16> vi16;
typedef vector<i32> vi32;
typedef vector<i64> vi64;

int main(){
    cin.tie(nullptr);

    i32 N;
    cin >> N;

    i32 order[N], L[N], R[N];
    rep(i, 0, N - 1){
        cin >> L[i] >> R[i];
        order[i] = i;
    }

    sort(order, order + N, [&](i32 a, i32 b){
        return R[a] < R[b];
    });

    i64 ans = 0;
    vi32 cand = { R[order[0]] };
    rep(i, 1, N - 1){
        i32 idx = lower_bound(all(cand), L[order[i]]) - cand.begin();
        ans += i - idx;

        cand.push_back(R[order[i]]);
    }

    cout << ans << endl;
    return(0);
}
