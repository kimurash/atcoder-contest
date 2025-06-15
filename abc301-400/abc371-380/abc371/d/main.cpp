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

    i32 N;
    cin >> N;

    i32 X[N + 1];
    rep(i, 1, N){
        cin >> X[i];
    }
    i32 P[N + 1];
    rep(i, 1, N){
        cin >> P[i];
    }

    i64 acc[N + 1] = {0};
    rep(i, 1, N){
        acc[i] = acc[i - 1] + P[i];
    }

    i32 Q;
    cin >> Q;

    i32 L, R;
    rep(i, 1, Q){
        cin >> L >> R;
        i32 r = upper_bound(X + 1, X + N + 1, R) - X;
        i32 l = lower_bound(X + 1, X + N + 1, L) - X;
        cout << acc[r - 1] - acc[l - 1] << endl;
    }

    return(0);
}
